/*********************************************************************
 *
 * Title:            LoggerTrim.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (houghton@cworld)
 *
 * Start Date:	    07/06/94 10:39
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.3  1995/11/10 01:01:43  houghton
 * Major rework. Uses new TempFileName function. Greater Error checking
 * and reporting.
 *
 * Revision 2.2  1995/10/29  18:16:01  houghton
 * Fixes for Borland 4.0 Port
 *
 * Revision 2.1  1995/10/29  12:01:20  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:28  houghton
 * Move to Version 2.0
 *
 * Revision 1.6  1995/02/13  15:34:18  houghton
 * New functions and many enhancements to existing functions.
 *
 * Revision 1.5  1994/08/15  19:57:07  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.4  1994/08/15  19:40:19  houghton
 * Cleanup; Rating QA1 Checkin
 *
 * Revision 1.3  1994/06/20  15:28:40  dpotluri
 * LibCommon Port to OPENVMS
 *
 * Revision 1.2  1994/06/20  10:27:19  houghton
 * Porting and add LoggerLoc function
 *
 * Revision 1.1  1994/06/17  18:07:29  houghton
 * Cool new Logger function
 *
 *
 *********************************************************************/
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




/**
 *             This software is the sole property of
 *
 *                 The Williams Companies, Inc.
 *                       1 Williams Center
 *                         P.O. Box 2400
 *                      Tulsa, Oklahoma 74102
 *
 *        Copyright (c) 1993 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/
