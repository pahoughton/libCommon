/* 1995-11-06 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"

COMMON_VERSION(
  LoggerSetLevel,
  "$Id$" );

extern LogLevelBit	_CLogCurMesgLevel;  /* Logger.c */

LogLevelBit
LoggerSetLevel( LogLevelBit bit )
{
  LogLevelBit old = _CLogCurMesgLevel;
  _CLogCurMesgLevel = bit;
  return( old );
}
