/*********************************************************************
 *
 * Title:            LoggerInit.c
 *
 * Description:
 *
 *	Initialize program logger variables.
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (houghton@cworld)
 *
 * Start Date:	    07/06/94 08:58
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.4  1994/08/15  19:40:18  houghton
 * Cleanup; Rating QA1 Checkin
 *
 * Revision 1.3  1994/07/13  13:43:00  houghton
 * Added LoggerTee function and fixed some bugs with logging
 *
 * Revision 1.2  1994/07/05  21:39:14  houghton
 * Minor fixes and cleanup header info.
 *
 * Revision 1.1  1994/06/17  18:07:29  houghton
 * Cool new Logger function
 *
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";

#include "_Common.h"
#include <Common.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char _CLogFilePath[256] = ".";
char _CLogFileName[256] = "program.log";

int _CLogFileType    = LOG_REOPEN;
long _CLogMaxSize    = 0;
long _CLogTrim       = 0;

int _CLogOutputLevel    = LOG_WARN | LOG_ERROR;
Bool _CLogDate	        = TRUE;
Bool _CLogLoc           = TRUE;
Bool _CLogTee		= TRUE;

FILE * _CLogFP = NULL;

LogBit _CLogCurMesgLevel = LOG_NONE;
const char * _CLogLocFile = "unknown";
int 	     _CLogLocLine = -1;


void
LoggerInit(
    const char *      logPath,
    const char *      logFileName,
    LogOutFileType    outputFileType,
    long	      maxByteCount,
    long	      trimIncrement,
    LogSetLevelType   setType,
    int		      outputLevels,
    Bool	      outputDate,
    Bool	      outputSourceLoc
    )
{

  if( logPath != NULL )
    {
      strncpy( _CLogFilePath, logPath, sizeof( _CLogFilePath ) - 2 );
      _CLogFilePath[sizeof( _CLogFilePath ) - 2] = 0;
    }

  if( logFileName != NULL )
    {
      strncpy( _CLogFileName, logFileName, sizeof( _CLogFileName ) - 2 );
      _CLogFileName[ sizeof( _CLogFileName ) - 2] = 0;
    }

  _CLogFileType = outputFileType;
  _CLogMaxSize  = maxByteCount;
  _CLogTrim     = trimIncrement;

  switch( setType )
    {
    case LOG_SET:
      _CLogOutputLevel = outputLevels;
      break;

    case LOG_ON:
      _CLogOutputLevel |= outputLevels;
      break;

    case LOG_OFF:
      _CLogOutputLevel ^= outputLevels;
      break;

    default:
      _CLogOutputLevel = outputLevels;
      break;

    }

  
  _CLogDate = outputDate;
  _CLogLoc  = outputSourceLoc;

  if( _CLogFileType != LOG_REOPEN )
    {
      char logFn[1024];

      _LoggerFileName( logFn, sizeof( logFn ) );
      
      _CLogFP = fopen( logFn, "a" );
    }
      
  return;
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
