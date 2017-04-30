/* 1994-07-07 (cc) Paul Houghton <paul4hough@gmail.com>

 	Converts a string containing log levels into a value that can
 	be used as the outputLevel parameter to LoggerInit(3) or
 	LoggerSetOutputLevel(3). This function was developed to make
 	it easy to convert command line arguments.

*/

#include "_Common.h"
#include <string.h>

COMMON_VERSION(
  LogLevelFromString,
  "$Id$");


LogLevelBit  LogLevels[] =
{
  LOG_NONE,
  LOG_ERROR,
  LOG_WARN,
  LOG_APP1,
  LOG_APP2,
  LOG_APP3,
  LOG_APP4,
  LOG_APP5,
  LOG_APP6,
  LOG_WCF1,
  LOG_WCF2,
  LOG_WCF3,
  LOG_WCF4,
  LOG_INFO,
  LOG_TEST,
  LOG_DEBUG,
  LOG_FUNCT,
  LOG_ALL
};

extern const char * _CLogLevelNames[];	/* LogLevelString.c */


int
LogLevelFromString( const char * levelString )
{

  int level = 0;
  int l;

  for( l = 0; _CLogLevelNames[l] != 0; l++ )
    {
      if( strstr( levelString, _CLogLevelNames[l] ) != NULL )
	{
	  level |= LogLevels[l];
	}
    }

  return( level );
}
