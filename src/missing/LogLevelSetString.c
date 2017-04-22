/*********************************************************************
 *
 * Title:            LogLevelSetString.c
 *
 * Description:
 *
 *	Provides a way to specify the string that will be output to
 *	represent a specific LogLevelBit. 
 *
 * Notes:
 *
 *	The string is not copied. It is directly accessed by the
 *	logger functions.
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/06/95 09:47
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.3  1998/09/22 14:32:46  houghton
 * Port(Linux): I was using 'index' as a variable name. This is also a
 *     syninoum for strchr(), so I change the variable name to avoid
 *     warnings.
 *
 * Revision 2.2  1997/05/07 11:36:56  houghton
 * Cleanup
 *
 * Revision 2.1  1995/11/10 00:56:01  houghton
 * Initial Version
 *
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





