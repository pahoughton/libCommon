/*********************************************************************
 *
 * Title:            Logger.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (houghton@cworld)
 *
 * Start Date:	    07/06/94 09:53
 *
 * Modification History:
 *
 * $Log$
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";

#include <stdio.h>
#include <stdarg.h>
#include <sys/stat.h>

#include "_Common.h"


extern char _CLogFilePath[];  /* = "." */
extern char _CLogFileName[];  /* = "prog.log" */

extern int _CLogFileType;     /* = LOG_REOPEN */
extern long _CLogMaxSize;     /* = 0 */
extern long _CLogTrim;        /* = 0 */

extern int _CLogOutputLevel;  /* = LOG_WARN | LOG_ERROR */
extern Bool _CLogDate;        /* = TRUE */
extern Bool _CLogLoc ;        /* = TRUE */


extern FILE * _CLogFP;

void
Logger(
    const char * mesgFmt,
    ...
    )
{

  va_list   args;

  va_start( args, mesgFmt );
  
  if( _CLogMaxSize != 0 )
    {
      if( _CLogFP != NULL )
	{
	  struct stat statBuf;
	  
	  if( fstat( fileno( _CLogFP ), &statBuf ) == 0 )
	    {
	      if( statBuf.st_size > _CLogMaxSize )
		{
		  close( _CLogFP );
		  _CLogFP = NULL;
		  LoggerTrim();
		}
	    }
	}
      else
	{
	  char logFn[1024];
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
      char logFn[ 1024 ];

      _LoggerFileName( logFn, sizeof( logFn ) );
      _CLogFP = fopen( logFn, "a" );
      
    }

  if( _CLogFP == NULL )
    {
      _CLogFP = stderr;
    }

  if( _CLogDate == TRUE )
    {
      time_t  nowSec = time(0);
      struct tm * now = localtime( &nowSec );
	   
      fprintf( _CLogFP,"%02d/%02d/%02d %02d:%02d:%02d ",
	       now->tm_mon,
	       now->tm_mday,
	       now->tm_year,
	       now->tm_hour,
	       now->tm_min,
	       now->tm_sec );
    }

  if( _CLogLoc == TRUE )
    {
      fprintf( _CLogFP,"%s (%d): ",
	       _CLogLocFile,
	       _CLogLocLine );
    }

  fprintf( _CLogFP, "%s: ", LogLevelString( _CLogCurMesgLevel ) );

  vfprintf( _CLogFP, mesgFmt, args );
  fputc( '\n', _CLogFP );

  va_end( args );

  if( _CLogFileType == LOG_REOPEN )
    {
      close( _CLogFP );
      _CLogFP = NULL;

    }
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
