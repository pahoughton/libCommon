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
 * Revision 2.1  1995/11/10 00:56:04  houghton
 * Initial Version
 *
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
