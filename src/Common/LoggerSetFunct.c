/*********************************************************************
 *
 * Title:            LoggerSetFunct.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/08/95 03:30
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/11/10 00:56:03  houghton
 * Initial Version
 *
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  LoggerSetFunct,
  "$Id$" );

extern LoggerFunct  _CLoggerFunct;	/* LoggerArgs.c */
extern void *	    _CLoggerClosure;	/* LoggerArgs.c */

void
LoggerSetFunct( LoggerFunct funct, void * closure )
{
  if( funct != NULL )
    {
      _CLoggerFunct = funct;
      _CLoggerClosure = closure;
    }
}
