/*********************************************************************
 *
 * Title:            LibError.c
 *
 * Description:
 *
 *	Process library and application errors. Calls the
 *  	function specified with SetErrorHandler or prints the
 *  	error message to stderr if no error handler was installed.
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton (pah)
 *
 * Start Date:	    09/03/93 12:35
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/10/29  12:01:16  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:24  houghton
 * Move to Version 2.0
 *
 * Revision 1.5  1994/08/15  19:57:04  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.4  1994/07/13  19:04:32  dpotluri
 * Port to sun4, and defined strerror()
 *
 * Revision 1.3  1994/06/17  18:03:59  houghton
 * Cleanup for beta release.
 *
 *
 *********************************************************************/
#include "_Common.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


COMMON_VERSION(
  LibError,
  "$Id$");


char *	    	 CommonErrFile;
int  	    	 CommonErrLine;
int  	    	 CommonOsErr;
CommonErrorType  CommonErrno;
int		 CommonAppErrno;

void (*CommonErrorHandler_)( CommonErrorType error,
			     int 	     appErrno,
			     void * 	     closure,
        		     const char *    mesg ) = NULL;

void * CommonErrorClosure_ = NULL;
/*
 * Other available error info:
 *  CommonErrFile, CommonErrLine, CommonOsErr
 */

static char  ErrorMesgBuffer[ COMMON_MAX_ERR_MESG ];


void
LibError(
    CommonErrorType error,
    int             appError,
    void *	    closure,
    const char *    message,
    ...
    )
{
  va_list      args;

  va_start(args, message );
  
  if( CommonErrorHandler_ == NULL )
    {
      if( CommonErrFile != NULL )
	{
	  char   appErrStr[25];
	  sprintf( appErrStr,"App Err: %d",appError );
	  fprintf( stderr, "%s(%d): %s ",
		   CommonErrFile,
		   CommonErrLine,
		   (error == C_EOSERROR) ?
		   (const char *)strerror( CommonOsErr ) :
		   (error == C_EAPP ) ? appErrStr : ErrorString( error ) );
	}
      
      vfprintf( stderr, message, args );
    }
  else
    {
      vsprintf( ErrorMesgBuffer, message, args );
      if( closure == NULL )
	{
	  CommonErrorHandler_( error, appError,
			       CommonErrorClosure_,
			       ErrorMesgBuffer );
	}
      else
	{
	  CommonErrorHandler_( error, appError, closure, ErrorMesgBuffer );
	}
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
