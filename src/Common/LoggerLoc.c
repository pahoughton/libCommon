/*********************************************************************
 *
 * Title:            LoggerLoc.c
 *
 * Description:
 *
 *	Turn off/on location stamps in log output.
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe)
 *
 * Start Date:	    06/17/94 15:33
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.1  1994/06/20  10:27:19  houghton
 * Porting and add LoggerLoc function
 *
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";

#include "_Common.h"

extern Bool  _CLogLoc;

Bool
LoggerLoc(
    Bool  newState
    )
{

  Bool oldState = _CLogLoc;

  _CLogLoc = newState;

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
