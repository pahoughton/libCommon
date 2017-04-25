/*********************************************************************
 *
 * Title:            Error.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/07/95 10:26
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/11/10 00:48:33  houghton
 * Initial Version
 *
 *
 *********************************************************************/

#include "_Common.h"
#include <stdarg.h>

COMMON_VERSION(
  Error,
  "$Id$" );

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
