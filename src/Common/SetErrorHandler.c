/*********************************************************************
 *
 * File:        SetErrorHandler.c
 * Project:	Common
 * Desc:
 *
 *	Sepecify the function to call when an error occures.
 *	The error function is call from ErrorArgs.
 *
 * Notes:
 *
 * Author:	Paul A. Houghton - (paul.houghton@wcom.com)
 * Created:	01/29/94 20:26
 *
 * Revision History: (See end of file for Revision Log)
 *
 *  Last Mod By:    $Author$
 *  Last Mod:	    $Date$
 *  Version:	    $Revision$
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  SetErrorHandler,
  "$Id$");


extern CommonErrorHandler  _CommonHandleError;	    /* ErrorArgs.c */
extern void *		    _CommonClosureError;    /* ErrorArgs.c */

void
SetErrorHandler( CommonErrorHandler handler, void * closure )
{
  _CommonHandleError  = handler;
  _CommonClosureError = closure;
}

/*
 *
 * Revision Log:
 *
 * $Log$
 * Revision 2.4  1997/03/02 12:11:56  houghton
 * Bug-Fix: function name was missing a 'l'.
 *
 * Revision 2.3  1995/12/02 02:07:20  houghton
 * Bug fix - duplicate symbols.
 *
 * Revision 2.2  1995/11/10  01:02:52  houghton
 * Change error handler arguments.
 *
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
 */


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
