/*********************************************************************
 *
 * Title:            SetErrorHandler.c
 *
 * Description:
 *
 *	Sepecify the function to call when an error occures.
 *	The error function is call from LibError.
 *
 * Error Handling:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton (pah)
 *
 * Start Date:	    01/29/94 20:26
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.3  1994/06/17  18:04:01  houghton
 * Cleanup for beta release.
 *
 * Revision 1.2  1994/06/06  13:23:36  houghton
 * Avl and DateTime functions added for Rating
 *
 * Revision 1.1  1994/01/31  14:06:15  houghton
 * Add avl and some other minor functions
 *
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";

#include "_Common.h"

/* both these are defined in LibError.c */

extern void (*CommonErrorHandler_)( CommonErrorType error,
				    int 	    appErrno,
				    void *          closure,
				    const char *    mesg );

extern void * CommonErrorClosure_;

void
SetErrorHandler(
    void (*errorHandler)( CommonErrorType error,
			  int             appErrno,
			  void *          closure,
			  const char *	  mesg),
    void * closure
    )
{
  CommonErrorHandler_ = errorHandler;
  CommonErrorClosure_ = closure;
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
