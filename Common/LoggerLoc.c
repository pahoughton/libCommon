/* 1994-06-17 (cc) Paul Houghton <paul4hough@gmail.com>

   Turn off/on location stamps in log output.
*/
#include "_Common.h"

COMMON_VERSION(
  LoggerLoc,
  "$Id$");

extern const char *	_CLogLocFile;	/* Logger.c */
extern long		_CLogLocLine;	/* Logger.c */

void
LoggerLoc( const char * fileName, long lineNumber )
{
  _CLogLocFile = fileName;
  _CLogLocLine = lineNumber;
}
