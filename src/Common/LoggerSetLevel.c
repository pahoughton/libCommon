/*********************************************************************
 *
 * Title:            LoggerSetLevel.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/06/95 09:16
 *
 * Modification History:
 *
 * $Log$
 *
 *********************************************************************/

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
