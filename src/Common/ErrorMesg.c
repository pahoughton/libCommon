/*********************************************************************
 *
 * Title:            ErrorMesg.c
 *
 * Description:
 *
 *	
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
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  ErrorMesg,
  "$Id$" );

extern const char *	_CommonErrorSetFile;	/* SetError.c */
extern long		_CommonErrorSetLine;	/* SetError.c */
extern CommonErrorType	_CommonErrorSetType;	/* SetError.c */
extern int		_CommonErrorSetValue;	/* SetError.c */
extern void *		_CommonErrorSetClosure; /* SetError.c */

int
ErrorMesg( char * mesgFormat, ... )
{
  int	    ret;
  va_list   args;

  va_start( args, mesgFormat );
  
  ret = ErrorArgs( _CommonErrorSetFile,
		   _CommonErrorSetLine,
		   _CommonErrorSetType,
		   _CommonErrorSetValue,
		   _CommonErrorSetClosure,
		   CommonErrorDesc,
		   mesgFormat,
		   args);

  va_end( args );

  return( ret );
  
}
