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
 * Revision 2.0  1995/10/28  17:35:25  houghton
 * Move to Version 2.0
 *
 * Revision 1.7  1995/02/13  15:34:18  houghton
 * New functions and many enhancements to existing functions.
 *
 * Revision 1.6  1994/08/15  19:57:06  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.5  1994/08/15  19:40:18  houghton
 * Cleanup; Rating QA1 Checkin
 *
 * Revision 1.4  1994/07/26  14:37:21  houghton
 * Fix basename in Common.h
 * Fix month in Logger
 *
 * Revision 1.3  1994/07/13  13:43:00  houghton
 * Added LoggerTee function and fixed some bugs with logging
 *
 * Revision 1.2  1994/06/20  15:28:40  dpotluri
 * LibCommon Port to OPENVMS
 *
 * Revision 1.1  1994/06/17  18:07:29  houghton
 * Cool new Logger function
 *
 *
 *********************************************************************/
#include "_Common.h"

#include <stdio.h>
#include <stdarg.h>

#if defined( OPENVMS )
#include <unixio.h>
#else
#include <sys/stat.h>
#endif

COMMON_VERSION(
  Logger,
  "$Id$" );



extern char _CLogFilePath[];  /* = "." */
extern char _CLogFileName[];  /* = "prog.log" */

extern int _CLogFileType;     /* = LOG_REOPEN */
extern long _CLogMaxSize;     /* = 0 */
extern long _CLogTrim;        /* = 0 */

extern int _CLogOutputLevel;  /* = LOG_WARN | LOG_ERROR */
extern BOOL _CLogDate;        /* = TRUE */
extern BOOL _CLogLoc ;        /* = TRUE */
extern BOOL _CLogTee;	      /* = TRUE */


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
		  fclose( _CLogFP );
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
	       now->tm_mon + 1,
	       now->tm_mday,
	       now->tm_year,
	       now->tm_hour,
	       now->tm_min,
	       now->tm_sec );
      
      if( _CLogTee == TRUE )
	{
	  
	  fprintf( stderr,"%02d/%02d/%02d %02d:%02d:%02d ",
		   now->tm_mon + 1,
		   now->tm_mday,
		   now->tm_year,
		   now->tm_hour,
		   now->tm_min,
		   now->tm_sec );
	}
    }
  
  if( _CLogLoc == TRUE )
    {
      fprintf( _CLogFP,"%s (%d): ",
	       _CLogLocFile,
	       _CLogLocLine );
      if( _CLogTee == TRUE )
	{
	  fprintf( stderr,"%s (%d): ",
		   _CLogLocFile,
		   _CLogLocLine );
	}
    }
  
  fprintf( _CLogFP, "%s: ", LogLevelString( _CLogCurMesgLevel ) );
  
  vfprintf( _CLogFP, mesgFmt, args );
  fputc( '\n', _CLogFP );
  
  if( _CLogTee == TRUE )
    {
      fprintf( stderr, "%s: ", LogLevelString( _CLogCurMesgLevel ) );
      
      vfprintf( stderr, mesgFmt, args );
      fputc( '\n', stderr );
      
    }      
  va_end( args );
  
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
