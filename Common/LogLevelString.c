/* 1994-07-18 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"

COMMON_VERSION(
  LogLevelString,
  "$Id$");


const char * _CLogLevelNames[] =
{
  "NONE",
  "ERROR",
  "WARN",
  "APP_1",
  "APP_2",
  "APP_3",
  "APP_4",
  "APP_5",
  "APP_6",
  "LIB_1",
  "LIB_2",
  "LIB_3",
  "LIB_4",
  "INFO",
  "TEST",
  "DEBUG",
  "FUNCT",
  "ALL",
  NULL
};

const char *
LogLevelString( LogLevelBit level )
{

  size_t	levNameIndex;

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
    case LOG_ALL:	levNameIndex = 17;  break;

    default:
      return( "UNKNOWN" );

    }

  return( _CLogLevelNames[ levNameIndex ] );
}
