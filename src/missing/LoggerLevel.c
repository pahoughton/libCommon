/*********************************************************************
 *
 * Title:            LoggerLevel.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/08/95 16:53
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/11/10 00:56:02  houghton
 * Initial Version
 *
 *
 *********************************************************************/

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


