/*********************************************************************
 *
 * Title:            GetErrorHandler.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/07/95 11:00
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/11/10 00:48:35  houghton
 * Initial Version
 *
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  GetErrorHandler,
  "$Id$" );

extern CommonErrorHandler  _CommonHandleError;	/* ErrorArgs.c */
extern void *		   _CommonClosureError; /* ErrorArgs.c */


void
GetErrorHandler( CommonErrorHandler * handler, void ** closure )
{
  *handler = _CommonHandleError;
  *closure = _CommonClosureError;
}
