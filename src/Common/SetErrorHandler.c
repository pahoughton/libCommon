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
 * Revision 2.1  1995/10/29  12:01:21  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:29  houghton
 * Move to Version 2.0
 *
 * Revision 1.4  1994/08/15  19:57:08  houghton
 * Fix RcsId so ident will work
 *
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
#include "_Common.h"

COMMON_VERSION(
  SetErrorHandler,
  "$Id$");


CommonErrorHandler  _CommonHandleError = _CommonDefaultErrorHandler;
void *		    _CommonClosureError = NULL;

void
SetErrorHander( CommonErrorHandler handler, void * closure )
{
  _CommonHandleError  = handler;
  _CommonClosureError = closure;
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
