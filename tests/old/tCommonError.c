/*********************************************************************
 *
 * File:        tCommonError.c
 * Project:	Common
 * Desc:
 *
 *  
 *
 * Notes:
 *
 * Author:	Paul A. Houghton - (paul.houghton@wcom.com)
 * Created:	04/29/97 04:57
 *
 * Revision History: (See end of file for Revision Log)
 *
 *  Last Mod By:    $Author$
 *  Last Mod:	    $Date$
 *  Version:	    $Revision$
 *
 *********************************************************************/

#include <Common.h>
#include <stdio.h>
#include <errno.h>

int
ErrorHandler(
  void *	    closure,
  const char *	    srcFile,
  long		    srcLine,
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

  LoggerArgs( srcFile,
	      srcLine,
	      LOG_ERROR,
	      NULL,
	      ( ( DefaultErrorMesg[0] != 0 ) ? DefaultErrorMesg : mesgFormat ),
	      args );

  return( INT_MAX );
}

BOOL
tCommonError( void )
{
  fprintf( stderr, "\n" );
  
  SetErrorHandler( ErrorHandler, NULL );

  ERROR( ET_COMMON, EC_RANGE, ("Testing ERROR with: %s %s\n",
			       "ET_COMMON",
			       "EC_RANGE" ) );

  ERROR( ET_OSERROR, ENOENT, ("Testing ERROR with: %s %s\n",
			      "ET_OSERROR",
			      "ENOENT" ) );
  
  return( TRUE );
}

/*
 *
 * Revision Log:
 *
 * $Log$
 * Revision 2.1  1997/05/07 11:38:20  houghton
 * Initial version.
 *
 *
 */
