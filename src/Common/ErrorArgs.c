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
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  ErrorArgs,
  "$Id$" );

CommonErrorHandler	_CommonHandleError  = _CommonDefaultErrorHandler;
void *			_CommonClosureError = NULL;

extern const char *	_CommonErrorSetFile;	/* SetError.c */
extern long		_CommonErrorSetLine;	/* SetError.c */
extern CommonErrorType	_CommonErrorSetType;	/* SetError.c */
extern int		_CommonErrorSetValue;	/* SetError.c */
extern void *		_CommonErrorSetClosure; /* SetError.c */


CommonError	CommonErrno	= EC_NONE;
const char *	CommonErrorDesc	= NULL;
const char *	CommonErrorFile = NULL;
long		CommonErrorLine = 0;

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
				  CommonErrorDesc : errorDesc ),
				mesgFormat,
				args );

  CommonErrno = EC_NONE;
  CommonErrorDesc = NULL;
  CommonErrorFile = NULL;
  CommonErrorLine = 0;

  _CommonErrorSetFile	    = NULL;
  _CommonErrorSetLine	    = 0;
  _CommonErrorSetType	    = ET_NONE;
  _CommonErrorSetValue	    = 0;
  _CommonErrorSetClosure    = 0;

  return( ret );
}

  

