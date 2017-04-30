/* 1995-11-07 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"

COMMON_VERSION(
  SetError,
  "$Id$" );

const char *	CommonErrFile	    = NULL;
long		CommonErrLine	    = 0;
CommonErrorType	CommonErrType	    = ET_NONE;
CommonError	CommonErrValue	    = 0;
void *		CommonErrClosure    = NULL;
const char *	CommonErrDesc	    = NULL;

void
SetError(
  const char *	    srcFileName,
  long		    srcLineNumber,
  CommonErrorType   errorType,
  int		    errorValue,
  const char *	    errorDesc,
  void *	    closure
  )
{

  CommonErrFile		= srcFileName;
  CommonErrLine		= srcLineNumber;
  CommonErrType		= errorType;
  CommonErrValue	= errorValue;
  CommonErrClosure	= closure;

  if( errorDesc )
    CommonErrDesc = errorDesc;

}
