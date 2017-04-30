/* 1995-11-10 (cc) Paul Houghton <paul4hough@gmail.com>
 */

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
