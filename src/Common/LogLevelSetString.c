/*********************************************************************
 *
 * Title:            LogLevelSetString.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/06/95 09:47
 *
 * Modification History:
 *
 * $Log$
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  LogLevelSetString,
  "$Id$" );

extern const char * _CLogLevelNames[]; /* LogLevelString */


const char *
LogLevelSetString( LogLevelBit level, const char * string )
{
  size_t	index;
  const char *	old;
  
  switch( level )
    {
    case LOG_NONE:      index =  0;  break;
    case LOG_ERROR:     index =  1;  break;
    case LOG_WARN:      index =  2;  break;
    case LOG_APP1:      index =  3;  break;
    case LOG_APP2:      index =  4;  break;
    case LOG_APP3:      index =  5;  break;
    case LOG_APP4:      index =  6;  break;
    case LOG_APP5:      index =  7;  break;
    case LOG_APP6:      index =  8;  break;
    case LOG_WCF1:      index =  9;  break;
    case LOG_WCF2:      index = 10;  break;
    case LOG_WCF3:      index = 11;  break;
    case LOG_WCF4:      index = 12;  break;
    case LOG_INFO:      index = 13;  break;
    case LOG_TEST:      index = 14;  break;
    case LOG_DEBUG:     index = 15;  break;
    case LOG_FUNCT:     index = 16;  break;

    default:
      return( 0 );
      
    }

  old = _CLogLevelNames[ index ];
  _CLogLevelNames[ index ] = string;

  return( old );
}





