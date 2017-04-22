/*********************************************************************
 *
 * Title:            ErrorMesg.c
 *
 * Description:
 *
 *	Call the error handler using the values establised by
 *	SetError.
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/07/95 11:02
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.4  1997/09/19 09:06:08  houghton
 * Changed: renamed CommonError* variables to CommonErr becuase of conflict with
 *     enum names.
 * Changed to use global public variables (CommonErr*) for error info
 *     instead of private (_CommonError*) variables.
 * Removed _CommonError* global variables.
 *
 * Revision 2.3  1997/05/07 11:36:56  houghton
 * Cleanup
 *
 * Revision 2.2  1997/03/03 14:12:38  houghton
 * Bug-Fix: changed ErrorMesg arg type to const char *.
 *
 * Revision 2.1  1995/11/10 00:48:34  houghton
 * Initial Version
 *
 *
 *********************************************************************/

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
