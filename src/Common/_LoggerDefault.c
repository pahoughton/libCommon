/*********************************************************************
 *
 * Title:            _LoggerDefault.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/06/95 11:07
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.2  1999/05/14 10:21:17  houghton
 * Port(Linux): stdout is not a constant in Gnu Libc 2.
 *
 * Revision 2.1  1995/11/10 00:56:08  houghton
 * Initial Version
 *
 *
 *********************************************************************/

#include "_Common.h"

#include <stdio.h>
#include <stdarg.h>

#include <sys/stat.h>


COMMON_VERSION(
  _LoggerDefault,
  "$Id$" );

int		_CLogOutputLevel    = LOG_WARN | LOG_ERROR;

LogOutFileType	_CLogFileType	    = LOG_STDOUT;

long		_CLogMaxSize	    = 0;
long		_CLogTrim	    = 0;

FILE *		_CLogFP		    = 0;

LogLevelBit	_CLogCurMesgLevel   = LOG_NONE;
const char *	_CLogLocFile	    = "unknown";
long		_CLogLocLine	    = 0;


void
_LoggerDefault(
  void *	closure,
  const char *  srcFileName,
  long		srcLineNumber,
  LogLevelBit   level,
  const char *  mesgFmt,
  va_list	mesgArgs
  )
{
  if( _CLogFileType != LOG_STDOUT )
    {
      if( _CLogMaxSize != 0 )
	{
	  if( _CLogFP != NULL )
	    {
	      struct stat statBuf;
	      
	      if( fstat( fileno( _CLogFP ), &statBuf ) == 0 )
		{
		  if( statBuf.st_size > _CLogMaxSize )
		    {
		      fclose( _CLogFP );
		      _CLogFP = NULL;
		      LoggerTrim();
		    }
		}
	    }
	  else
	    {
	      char logFn[ COMMON_PATH_MAX + FILENAME_MAX + 10 ];
	      struct stat statBuf;
	  
	      _LoggerFileName( logFn, sizeof( logFn ) );
	  
	      if( stat( logFn, &statBuf ) == 0 )
		{
		  if( statBuf.st_size > _CLogMaxSize )
		    {
		      LoggerTrim();
		    }
		}
	    }
	}
  
      if( _CLogFP == NULL )
	{
	  char logFn[ COMMON_PATH_MAX + FILENAME_MAX + 10 ];
	  
	  _LoggerFileName( logFn, sizeof( logFn ) );
	  _CLogFP = fopen( logFn, "a" );
	  
	}
  
    }
  
  if( _CLogFP == NULL )
    {
      _CLogFP = stdout;
    }

  _LoggerLogIt( _CLogFP,
		srcFileName,
  		srcLineNumber,
		level,
		mesgFmt,
		mesgArgs );
  
  if( _CLogFileType == LOG_REOPEN )
    {
      fclose( _CLogFP );
      _CLogFP = NULL;
    }
  else
    {
      fflush( _CLogFP );
    }
}
		
