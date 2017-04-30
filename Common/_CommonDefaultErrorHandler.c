/* 1995-11-07 (cc) paul4hough@gmail.com
 */

#include "_Common.h"
#include <limits.h>


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
  static char DefaultErrorMesg[ 2048 ];

  DefaultErrorMesg[0] = 0;

  switch( errorType )
    {
    case ET_OSERROR:
      sprintf( DefaultErrorMesg, "%s: (%d) %s ",
	       ErrorTypeString( errorType ),
	       errorValue,
	       strerror( errorValue ) );
      break;

    case ET_COMMON:
      sprintf( DefaultErrorMesg, "%s: %s ",
	       ErrorTypeString( errorType ),
	       CommonErrorString( errorValue ) );

      break;

    default:
      sprintf( DefaultErrorMesg, "%s(%d): ",
	       ErrorTypeString( errorType ),
	       errorValue );
      break;
    }

  if( errorDesc &&
      ( strlen( DefaultErrorMesg ) + strlen( errorDesc ) + 10 )
      < sizeof( DefaultErrorMesg ) )
    {
      strcat( DefaultErrorMesg, errorDesc );
      strcat( DefaultErrorMesg, " " );
    }

  if( (strlen( DefaultErrorMesg ) + strlen( mesgFormat ) + 10 )
      < sizeof( DefaultErrorMesg ) )
    {
      strcat( DefaultErrorMesg, mesgFormat );
    }
  else
    {
      DefaultErrorMesg[0] = 0;
    }

  LoggerArgs( srcFileName,
	      srcLineNumber,
	      LOG_ERROR,
	      closure,
	      ( ( DefaultErrorMesg[0] != 0 ) ?
		DefaultErrorMesg : mesgFormat ),
	      args );

  return( INT_MAX );
}
