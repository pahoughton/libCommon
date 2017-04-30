/* 1994-07-06 (cc) Paul Houghton <paul4hough@gmail.com>

   Initialize program logger variables.
*/
#include "_Common.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

COMMON_VERSION(
  LoggerInit,
  "$Id$" );



Ret_Status
LoggerInit(
  const char *      logPath,
  const char *      logFileName,
  LogOutFileType    outputFileType,
  long		    maxByteCount,
  long		    trimIncrement,
  LogSetLevelType   setType,
  int		    outputLevels,
  BOOL		    outputDate,
  BOOL		    outputSourceLoc,
  BOOL		    teeOutput,
  LoggerFunct	    funct,
  void *	    closure
  )
{
  if( LoggerSetLogFile( logPath,
			logFileName,
			outputFileType,
			maxByteCount,
			trimIncrement ) != RET_SUCCEED )
    {
      return( RET_ERROR );
    }

  LoggerSetOutputLevel(  setType, outputLevels );

  LoggerSetDate( outputDate );
  LoggerSetLoc( outputSourceLoc );
  LoggerSetTee( teeOutput );
  LoggerSetFunct( funct, closure );

  return( RET_SUCCEED );
}
