/* 1995-11-07 (cc) Paul Houghton <paul4hough@gmail.com>

   Call the error handler using the values establised by
   SetError.
*/

#include "_Common.h"

COMMON_VERSION(
  ErrorMesg,
  "$Id$" );

int
ErrorMesg( const char * mesgFormat, ... )
{
  int	    ret;
  va_list   args;

  va_start( args, mesgFormat );

  ret = ErrorArgs( CommonErrFile,
		   CommonErrLine,
		   CommonErrType,
		   CommonErrValue,
		   CommonErrClosure,
		   CommonErrDesc,
		   mesgFormat,
		   args);

  va_end( args );

  return( ret );

}
