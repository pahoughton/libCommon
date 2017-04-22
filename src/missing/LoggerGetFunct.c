/*********************************************************************
 *
 * Title:            LoggerGetFunct.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/08/95 03:32
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
  LoggerGetFunct,
  "$Id$" );

extern LoggerFunct  _CLoggerFunct;	/* LoggerArgs.c */
extern void *	    _CLoggerClosure;	/* LoggerArgs.c */

void
LoggerGetFunct( LoggerFunct * funct, void ** closure )
{
  *funct = _CLoggerFunct;
  *closure = _CLoggerClosure;
}
  

