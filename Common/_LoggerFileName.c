/* 1994-07-06 (cc) Paul Houghton <paul4hough@gmail.com>
 */
#include "_Common.h"

#include <stdio.h>
#include <time.h>

COMMON_VERSION(
  _LoggerFileName,
  "$Id$");

char	_CLogFilePath[ COMMON_PATH_MAX + 5 ]     = ".";
char	_CLogFileName[ FILENAME_MAX + 5 ] = "00-APP.LOG";

extern LogOutFileType	_CLogFileType;	/* _LoggerDefault.c */

void
_LoggerFileName(
    char *  logFn,
    size_t  bufSize
    )
{
  strncpy( logFn, _CLogFilePath, bufSize - 2 );
  logFn[ bufSize - 2 ] = 0;

  strncat( logFn, "/", bufSize - 2  );
  logFn[ bufSize - 2  ] = 0;

  if( _CLogFileType == LOG_BY_DATE )
    {
      char timeStr[16];
      time_t  nowSec = time(0);
      struct tm * now = localtime( &nowSec );

      sprintf( timeStr, "%04d%02d%02d.",
	       now->tm_year + 1900,
	       now->tm_mon + 1,
	       now->tm_mday );

      strncat( logFn, timeStr, bufSize - 2 );
      logFn[ bufSize - 2 ] = 0;
    }

  strncat( logFn, _CLogFileName, bufSize - 2  );
  logFn[ bufSize - 2  ] = 0;
}
