/* 1995-11-08 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"

COMMON_VERSION(
  LoggerLevel,
  "$Id$" );

extern LogLevelBit _CLogCurMesgLevel;

LogLevelBit
LoggerLevel( LogLevelBit level )
{
  LogLevelBit old = _CLogCurMesgLevel;

  _CLogCurMesgLevel = level;

  return( old );
}
