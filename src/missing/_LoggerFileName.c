/*********************************************************************
 *
 * Title:            _LoggerFileName.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (houghton@cworld)
 *
 * Start Date:	    07/06/94 10:25
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.4  1998/09/22 14:35:46  houghton
 * Changed to use 4 digit year in file name.
 *
 * Revision 2.3  1995/12/02 02:10:36  houghton
 * Cleanup error messages.
 *
 * Revision 2.2  1995/11/10  01:03:51  houghton
 * Moved Global variables
 *
 * Revision 2.1  1995/10/29  12:01:28  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:38  houghton
 * Move to Version 2.0
 *
 * Revision 1.3  1994/08/15  19:57:10  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.2  1994/07/13  13:43:01  houghton
 * Added LoggerTee function and fixed some bugs with logging
 *
 * Revision 1.1  1994/06/17  18:07:30  houghton
 * Cool new Logger function
 *
 *
 *********************************************************************/
#include "_Common.h"

#include <stdio.h>
#include <time.h>

COMMON_VERSION(
  _LoggerFileName,
  "$Id$");

char	_CLogFilePath[ COMMON_PATH_MAX + 5 ]     = ".";
char	_CLogFileName[ FILENAME_MAX + 5 ] = "00-APP.LOG";

extern LogOutFileType	_CLogFileType;	/* _LoggerDefault.c */

void
_LoggerFileName(
    char *  logFn,
    size_t  bufSize
    )
{
  strncpy( logFn, _CLogFilePath, bufSize - 2 );
  logFn[ bufSize - 2 ] = 0;

  strncat( logFn, "/", bufSize - 2  );
  logFn[ bufSize - 2  ] = 0;

  if( _CLogFileType == LOG_BY_DATE )
    {
      char timeStr[16];
      time_t  nowSec = time(0);
      struct tm * now = localtime( &nowSec );
	   
      sprintf( timeStr, "%04d%02d%02d.",
	       now->tm_year + 1900,
	       now->tm_mon + 1,
	       now->tm_mday );

      strncat( logFn, timeStr, bufSize - 2 );
      logFn[ bufSize - 2 ] = 0;
    }

  strncat( logFn, _CLogFileName, bufSize - 2  );
  logFn[ bufSize - 2  ] = 0;
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
