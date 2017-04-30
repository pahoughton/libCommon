/* 1994-01-29 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"

COMMON_VERSION(
  SetErrorHandler,
  "$Id$");


extern CommonErrorHandler  _CommonHandleError;	    /* ErrorArgs.c */
extern void *		    _CommonClosureError;    /* ErrorArgs.c */

void
SetErrorHandler( CommonErrorHandler handler, void * closure )
{
  _CommonHandleError  = handler;
  _CommonClosureError = closure;
}
