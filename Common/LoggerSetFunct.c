/* 1995-11-08 (cc) Paul Houghton <paul4hough@gmail.com>
 */

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
