/*********************************************************************
 *
 * Title:            SetError.c
 *
 * Description:
 *
 *	
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
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  SetError,
  "$Id$" );

const char *	_CommonErrorSetFile	= NULL;
long		_CommonErrorSetLine	= 0;
CommonErrorType	_CommonErrorSetType	= ET_NONE;
int		_CommonErrorSetValue	= 0;
void *		_CommonErrorSetClosure	= 0;


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
 
  _CommonErrorSetFile	    = srcFileName;
  _CommonErrorSetLine	    = srcLineNumber;
  _CommonErrorSetType	    = errorType;
  _CommonErrorSetValue	    = errorValue;
  _CommonErrorSetClosure    = closure;
  if( errorDesc )
    CommonErrorDesc = errorDesc;
  
}
 
