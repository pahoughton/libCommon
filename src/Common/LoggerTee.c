/*********************************************************************
 *
 * Title:            LoggerTee.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    07/12/94 08:04
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/10/29  12:01:19  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:27  houghton
 * Move to Version 2.0
 *
 * Revision 1.2  1994/08/15  19:57:07  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.1  1994/07/13  13:43:01  houghton
 * Added LoggerTee function and fixed some bugs with logging
 *
 *
 *********************************************************************/


#include "_Common.h"

COMMON_VERSION(
  LoggerTee,
  "$Id$");

extern BOOL _CLogTee;	/* LoggerArgs.c */

BOOL
LoggerTee( BOOL state )
{
  BOOL oldState = _CLogTee;

  _CLogTee = state;

  return( oldState );
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
