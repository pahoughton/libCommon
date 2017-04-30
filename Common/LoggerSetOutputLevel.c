/* 1995-11-06 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"

COMMON_VERSION(
  LoggerSetOutputLevel,
  "$Id$" );

int	_CLogOutputLevel; /* _LoggerDefault.c */

int
LoggerSetOutputLevel( LogSetLevelType setType, int outputLevels )
{
  int old = _CLogOutputLevel;

  switch( setType )
    {
    case LOG_ON:
      _CLogOutputLevel |= outputLevels;
      break;

    case LOG_OFF:
      _CLogOutputLevel ^= outputLevels;
      break;

    case LOG_SET:
    default:
      _CLogOutputLevel = outputLevels;
      break;

    }

  return( old );
}
