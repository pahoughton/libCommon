/*********************************************************************
 *
 * Title:            ErrorArgs.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/07/95 10:30
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/11/10 00:48:34  houghton
 * Initial Version
 *
 *
 *********************************************************************/

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

  

