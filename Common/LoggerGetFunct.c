/* 1995-11-08 (cc) Paul Houghton <paul4hough@gmail.com>
 */

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
