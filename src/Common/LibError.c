/*********************************************************************
 *
 * Title:            LibError.c
 *
 * Description:
 *
 *	
 *
 * Error Handling:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton (pah)
 *
 * Start Date:	    09/03/93 12:35
 *
 * Modification History:
 *
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <_Common.h>
#include <Common.h>

#define MAX_ERR_MESG	2048

extern void (*CommonErrorHandler_)( CommonErrorType error,
				    const char * mesg );
/*
 * Other available error info:
 *  CommonErrFile, CommonErrLine, CommonOsErr
 */

static char  ErrorMesgBuffer[ MAX_ERR_MESG ];


void
LibError(
    CommonErrorType error,
    const char * message,
    ...
    )
{
  va_list      args;

  va_start(args, message );
  
  if( CommonErrorHandler_ == NULL )
    {
      if( CommonErrFile != NULL )
	{
	  fprintf( stderr, "%s(%d): %s ",
		   CommonErrFile,
		   CommonErrLine,
		   (error == C_EOSERROR) ?
		       (const char *)strerror( CommonOsErr ) :  ErrorString( error ) );
	}
      
      vfprintf( stderr, message, args );
    }
  else
    {
      vsprintf( ErrorMesgBuffer, message, args );
      CommonErrorHandler_( error, ErrorMesgBuffer );
    }

  va_end( args );
  return;
  
}
	   



/**
 *             This software is the sole property of
 *
 *                 The Williams Companies, Inc.
 *                       1 Williams Center
 *                         P.O. Box 2400
 *                      Tulsa, Oklahoma 74102
 *
 *        Copyright (c) 1993 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/
