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
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";

#include <stdio.h>
#include <sys/stat.h>

#include "_Common.h"

extern long _CLogMaxSize;     /* = 0 */
extern long _CLogTrim;        /* = 0 */

extern char * _CLogFilePath;
extern char * _CLogFileName;

void
LoggerTrim( void )
{

  FILE * newLogFp;
  FILE * logFp;
  
  char logFn[1024];
  char newLogFn[1024];
  char line[2048];

  struct stat statBuf;
  int	 newSize = 0;
  int	 skipCount = 0;
  
  sprintf( logFn,"%s/trim.log",_CLogFilePath );
  
  _LoggerFileName( newLogFn, sizeof( logFn ) );

  if( stat( newLogFn, &statBuf ) != 0 )
    {
      return;
    }

  if( _CLogTrim == 0 )
    {
      _CLogTrim = min( _CLogMaxSize / 4, 2048 );
    }
  
  newSize = min( _CLogMaxSize, statBuf.st_size )  - _CLogTrim;

  skipCount = statBuf.st_size - newSize;
  
  rename( newLogFn, logFn );

  if( (logFp = fopen( logFn, "r" )) == NULL )
    {
      rename( logFn, newLogFn );
      return;
    }

  if( (newLogFp = fopen( newLogFn, "w" ) ) == NULL )
    {
      close( logFp );
      remove( logFn );
      rename( logFn, newLogFn );
    }

  
  
  while( fgets( line, sizeof(line), logFp ) != NULL )
    {
      if( skipCount > 0 )
	{
	  skipCount += strlen( line );
	}
      else
	{
	  fputs( line, newLogFp );
	}
    }

  fclose( newLogFp );
  fclose( logFp );
  remove( logFn );
  
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
