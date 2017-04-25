/*********************************************************************
 *
 * Title:            LoggerSetOutputLevel.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/06/95 09:14
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/11/10 00:56:05  houghton
 * Initial Version
 *
 *
 *********************************************************************/

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
