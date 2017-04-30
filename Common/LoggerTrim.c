/* 1994-07-06 (cc) Paul Houghton <paul4hough@gmail.com>
 */
#include "_Common.h"

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

COMMON_VERSION(
  LoggerTrim,
  "$Id$");



extern LogOutFileType   _CLogFileType;	/* _LoggerDefault.c */
extern char *		_CLogFilePath;	/* _LoggerFileName.c */
extern char *		_CLogFileName;	/* _LoggerFileName.c */

extern long		_CLogMaxSize;   /* _LoggerDefault.c */
extern long		_CLogTrim;      /* _LoggerDefault.c */

extern FILE *		_CLogFP;	/* _LoggerDefault.c */

Ret_Status
LoggerTrim( void )
{

  FILE *	newLogFp;
  FILE *	tempFp;
  struct stat	statBuf;

  const char *  tempFn;
  char		newLogFn[ COMMON_PATH_MAX + FILENAME_MAX + 10 ];
  char		line[2048];

  long		newSize = 0;
  long		skipCount = 0;

  if( _CLogFileType == LOG_STDOUT )
    return( RET_SUCCEED );

  tempFn = TempFileName( _CLogFilePath, "log.trim." );

  if( tempFn == NULL )
    return( RET_ERROR );

  if( _CLogFP != NULL )
    {
      fclose( _CLogFP );
      _CLogFP = NULL;
    }

  _LoggerFileName( newLogFn, sizeof( newLogFn ) );

  if( stat( newLogFn, &statBuf ) != 0 )	    /* file not found so it's empty */
    {
      return( RET_SUCCEED );
    }

  if( _CLogTrim == 0 )
    {
      _CLogTrim = min( _CLogMaxSize / 4, 2048 );
    }

  newSize = min( _CLogMaxSize, statBuf.st_size )  - _CLogTrim;

  skipCount = statBuf.st_size - newSize;

  if( rename( newLogFn, tempFn ) != 0 )
    {
      COMMON_RETURN_TYPE_ERROR( ET_OSERROR, errno,
				( "can't rename %s to %s",
				  newLogFn, tempFn ) );
    }

  if( (tempFp = fopen( tempFn, "r" )) == NULL )
    {
      COMMON_RETURN_TYPE_ERROR( ET_OSERROR, errno,
				( "can't open %s for reading",
				  tempFn ) );
    }

  if( (newLogFp = fopen( newLogFn, "w" ) ) == NULL )
    {
      fclose( tempFp );
      remove( tempFn );
      rename( tempFn, newLogFn );
      COMMON_RETURN_TYPE_ERROR( ET_OSERROR, errno,
				( "can't open %s for writing",
				  newLogFn ) );
    }

  while( fgets( line, sizeof(line), tempFp ) != NULL )
    {
      if( skipCount > 0 )
	{
	  skipCount += strlen( line );
	}
      else
	{
	  int count = fputs( line, newLogFp );

	  if( count != strlen( line ) )
	    {
	      fclose( newLogFp );
	      fclose( tempFp );
	      remove( tempFn );
	      COMMON_RETURN_TYPE_ERROR( ET_OSERROR, errno,
					( "wrote %d to '%s' tried %d",
					  count, newLogFn, strlen( line ) ) );
	    }
	}
    }

  fclose( newLogFp );
  fclose( tempFp );
  remove( tempFn );
  return( RET_SUCCEED );
}
