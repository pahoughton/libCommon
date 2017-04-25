/*********************************************************************
 *
 * Title:            LoggerInit.c
 *
 * Description:
 *
 *	Initialize program logger variables.
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (houghton@cworld)
 *
 * Start Date:	    07/06/94 08:58
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.4  1995/12/02 02:06:17  houghton
 * Reorder includes.
 *
 * Revision 2.3  1995/11/10  00:59:38  houghton
 * Moved functionallity to new Set functions for finer control
 * over logging. Also add arguments for user Logger Function
 *
 * Revision 2.2  1995/10/29  13:33:43  houghton
 * Initial Linux Build of Version 2
 *
 * Revision 2.1  1995/10/29  12:01:18  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:26  houghton
 * Move to Version 2.0
 *
 * Revision 1.5  1994/08/15  19:57:06  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.4  1994/08/15  19:40:18  houghton
 * Cleanup; Rating QA1 Checkin
 *
 * Revision 1.3  1994/07/13  13:43:00  houghton
 * Added LoggerTee function and fixed some bugs with logging
 *
 * Revision 1.2  1994/07/05  21:39:14  houghton
 * Minor fixes and cleanup header info.
 *
 * Revision 1.1  1994/06/17  18:07:29  houghton
 * Cool new Logger function
 *
 *
 *********************************************************************/
#include "_Common.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

COMMON_VERSION(
  LoggerInit,
  "$Id$" );



Ret_Status
LoggerInit(
  const char *      logPath,
  const char *      logFileName,
  LogOutFileType    outputFileType,
  long		    maxByteCount,
  long		    trimIncrement,
  LogSetLevelType   setType,
  int		    outputLevels,
  BOOL		    outputDate,
  BOOL		    outputSourceLoc,
  BOOL		    teeOutput,
  LoggerFunct	    funct,
  void *	    closure
  )
{
  if( LoggerSetLogFile( logPath,
			logFileName,
			outputFileType,
			maxByteCount,
			trimIncrement ) != RET_SUCCEED )
    {
      return( RET_ERROR );
    }
  
  LoggerSetOutputLevel(  setType, outputLevels );

  LoggerSetDate( outputDate );
  LoggerSetLoc( outputSourceLoc );
  LoggerSetTee( teeOutput );
  LoggerSetFunct( funct, closure );
  
  return( RET_SUCCEED );
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
