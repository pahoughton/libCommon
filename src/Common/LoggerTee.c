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
 * Revision 1.2  1994/08/15  19:57:07  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.1  1994/07/13  13:43:01  houghton
 * Added LoggerTee function and fixed some bugs with logging
 *
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";

#include <Common.h>

extern Bool _CLogTee;

Bool
LoggerTee( Bool state )
{
  Bool oldState = _CLogTee;

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
