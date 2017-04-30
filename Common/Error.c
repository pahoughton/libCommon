/* 1995-11-07 (cc) paul4hough@gmail.com
 */

#include "_Common.h"
#include <stdarg.h>


int
Error(
  const char *	    srcFileName,
  long		    srcLineNumber,
  CommonErrorType   errorType,
  int		    errorValue,
  void *	    closure,
  const char *	    errorDesc,
  const char *	    mesgFormat,
  ...
  )
{
  int	ret;

  va_list   args;

  va_start( args, mesgFormat );

  ret = ErrorArgs( srcFileName,
		   srcLineNumber,
		   errorType,
		   errorValue,
		   closure,
		   errorDesc,
		   mesgFormat,
		   args );

  va_end( args );

  return( ret );
}
