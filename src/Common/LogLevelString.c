/*********************************************************************
 *
 * Title:            LogLevelString.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (houghton@cworld.wiltel.com)
 *
 * Start Date:	    07/18/94 12:36
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.4  1998/09/22 14:32:57  houghton
 * Port(Linux): I was using 'index' as a variable name. This is also a
 *     syninoum for strchr(), so I change the variable name to avoid
 *     warnings.
 *
 * Revision 2.3  1997/05/07 11:36:57  houghton
 * Cleanup
 *
 * Revision 2.2  1995/11/10 00:57:21  houghton
 * Restructured to improve readability and move Global Values
 *
 * Revision 2.1  1995/10/29  12:01:17  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:25  houghton
 * Move to Version 2.0
 *
 * Revision 1.2  1994/08/15  19:57:05  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.1  1994/06/17  18:07:28  houghton
 * Cool new Logger function
 *
 *
 *********************************************************************/

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

