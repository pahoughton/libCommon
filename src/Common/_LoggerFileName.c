/*********************************************************************
 *
 * Title:            _LoggerFileName.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (houghton@cworld)
 *
 * Start Date:	    07/06/94 10:25
 *
 * Modification History:
 *
 * $Log$
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";

#include <stdio.h>
#include <time.h>

#include "_Common.h"

extern char * _CLogFilePath;
extern int    _CLogFileType;
extern char * _CLogFileName;

void
_LoggerFileName(
    char * logFn,
    int    bufSize
    )
{
  strncpy( logFn, _CLogFilePath, bufSize - 2 );
  logFn[ bufSize - 2 ] = 0;

  strncat( logFn, "/", bufSize - 2  );
  logFn[ bufSize - 2  ] = 0;

  if( _CLogFileType == LOG_BY_DATE )
    {
      char timeStr[10];
      time_t  nowSec = time(0);
      struct tm * now = localtime( &nowSec );
	   
      sprintf( timeStr, "%02d%02d%02d.",
	       now->tm_year,
	       now->tm_mon,
	       now->tm_mday );

      strncat( logFn, timeStr, bufSize - 2 );
      logFn[ bufSize - 2 ] = 0;
    }

  strncat( logFn, _CLogFileName, bufSize - 2  );
  logFn[ bufSize - 2  ] = 0;
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
