/* 1995-11-07 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"

COMMON_VERSION(
  ErrorArgs,
  "$Id$" );

CommonErrorHandler	_CommonHandleError  = _CommonDefaultErrorHandler;
void *			_CommonClosureError = NULL;

int
ErrorArgs(
  const char *	    srcFileName,
  long		    srcLineNumber,
  CommonErrorType   errorType,
  int		    errorValue,
  void *	    closure,
  const char *	    errorDesc,
  const char *	    mesgFormat,
  va_list	    args
  )
{
  int ret = _CommonHandleError( ( ( closure != NULL ) ?
				  closure : _CommonClosureError ),
				srcFileName,
				srcLineNumber,
				errorType,
				errorValue,
				( ( errorDesc == NULL ) ?
				  CommonErrDesc : errorDesc ),
				mesgFormat,
				args );

  CommonErrFile	    = NULL;
  CommonErrLine	    = 0;
  CommonErrType	    = ET_NONE;
  CommonErrValue    = 0;
  CommonErrClosure  = 0;

  return( ret );
}
