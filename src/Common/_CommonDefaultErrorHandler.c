/*********************************************************************
 *
 * Title:            _CommonDefaultErrorHandler.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/07/95 10:40
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/11/10  00:56:07  houghton
 * Initial Version
 *
 *
 *********************************************************************/

#include "_Common.h"
#include <limits.h>

COMMON_VERSION(
  _CommonDefaultErrorHandler,
  "$Id$" );

int
_CommonDefaultErrorHandler(
  void *	    closure,
  const char *	    srcFileName,
  long		    srcLineNumber,
  CommonErrorType   errorType,
  int		    errorValue,
  const char *	    errorDesc,
  const char *	    mesgFormat,
  va_list	    args
  )
{
  static char ErrorMesg[ 2048 ];

  ErrorMesg[0] = 0;
  
  switch( errorType )
    {
    case ET_OSERROR:
      sprintf( ErrorMesg, "%s: (%d) %s ",
	       ErrorTypeString( errorType ),
	       errorValue,
	       strerror( errorValue ) );
      break;

    case ET_COMMON:
      sprintf( ErrorMesg, "%s: %s ",
	       ErrorTypeString( errorType ),
	       CommonErrorString( errorValue ) );
      
      break;

    default:
      sprintf( ErrorMesg, "%s(%d): ",
	       ErrorTypeString( errorType ),
	       errorValue );
      break;
    }

  if( errorDesc &&
      ( strlen( ErrorMesg ) + strlen( errorDesc ) + 10 )
      < sizeof( ErrorMesg ) )
    {
      strcat( ErrorMesg, errorDesc );
      strcat( ErrorMesg, " " );
    }
      
  if( (strlen( ErrorMesg ) + strlen( mesgFormat ) + 10 )
      < sizeof( ErrorMesg ) )
    {
      strcat( ErrorMesg, mesgFormat );
    }
  else
    {
      ErrorMesg[0] = 0;
    }

  LoggerArgs( srcFileName,
	      srcLineNumber,
	      LOG_ERROR,
	      closure,
	      ( ( ErrorMesg[0] != 0 ) ?
		ErrorMesg : mesgFormat ),
	      args );

  return( INT_MAX );
}
	      

