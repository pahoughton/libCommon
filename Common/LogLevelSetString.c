/* 1995-11-06 (cc) Paul Houghton <paul4hough@gmail.com>

   Provides a way to specify the string that will be output to
   represent a specific LogLevelBit.
*/

#include "_Common.h"

COMMON_VERSION(
  LogLevelSetString,
  "$Id$" );

extern const char * _CLogLevelNames[]; /* LogLevelString */


const char *
LogLevelSetString( LogLevelBit level, const char * string )
{
  size_t	levNameIndex;
  const char *	old;

  switch( level )
    {
    case LOG_NONE:      levNameIndex =  0;  break;
    case LOG_ERROR:     levNameIndex =  1;  break;
    case LOG_WARN:      levNameIndex =  2;  break;
    case LOG_APP1:      levNameIndex =  3;  break;
    case LOG_APP2:      levNameIndex =  4;  break;
    case LOG_APP3:      levNameIndex =  5;  break;
    case LOG_APP4:      levNameIndex =  6;  break;
    case LOG_APP5:      levNameIndex =  7;  break;
    case LOG_APP6:      levNameIndex =  8;  break;
    case LOG_WCF1:      levNameIndex =  9;  break;
    case LOG_WCF2:      levNameIndex = 10;  break;
    case LOG_WCF3:      levNameIndex = 11;  break;
    case LOG_WCF4:      levNameIndex = 12;  break;
    case LOG_INFO:      levNameIndex = 13;  break;
    case LOG_TEST:      levNameIndex = 14;  break;
    case LOG_DEBUG:     levNameIndex = 15;  break;
    case LOG_FUNCT:     levNameIndex = 16;  break;

    default:
      return( 0 );

    }

  old = _CLogLevelNames[ levNameIndex ];
  _CLogLevelNames[ levNameIndex ] = string;

  return( old );
}
