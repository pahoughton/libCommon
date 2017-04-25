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
 * Revision 2.3  1995/11/10 01:00:35  houghton
 * Changed function from set output to set the current location.
 *
 * Revision 2.2  1995/10/29  13:33:43  houghton
 * Initial Linux Build of Version 2
 *
 * Revision 2.1  1995/10/29  12:01:19  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:27  houghton
 * Move to Version 2.0
 *
 * Revision 1.2  1994/08/15  19:57:07  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.1  1994/06/20  10:27:19  houghton
 * Porting and add LoggerLoc function
 *
 *
 *********************************************************************/
#include "_Common.h"

COMMON_VERSION(
  LoggerLoc,
  "$Id$");

extern const char *	_CLogLocFile;	/* Logger.c */
extern long		_CLogLocLine;	/* Logger.c */

void
LoggerLoc( const char * fileName, long lineNumber )
{
  _CLogLocFile = fileName;
  _CLogLocLine = lineNumber;
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
