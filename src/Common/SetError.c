/*********************************************************************
 *
 * Title:            SetError.c
 *
 * Description:
 *
 *	Set the information for an error that has occured.
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/07/95 10:35
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.3  1997/09/19 09:07:03  houghton
 * Changed: renamed CommonError* variables to CommonErr becuase of conflict with
 *     enum names.
 * Changed to use global public variables (CommonErr*) for error info
 *     instead of private (_CommonError*) variables.
 * Removed _CommonError* global variables.
 *
 * Revision 2.2  1997/05/07 11:36:57  houghton
 * Cleanup
 *
 * Revision 2.1  1995/11/10 00:56:06  houghton
 * Initial Version
 *
 *
 *********************************************************************/

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
 
