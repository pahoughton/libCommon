/*********************************************************************
 *
 * Title:            Logger.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (houghton@cworld)
 *
 * Start Date:	    07/06/94 09:53
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.2  1995/11/10 00:58:12  houghton
 * Moved functionallity to LoggerArgs & _LoggerDefault
 *
 * Revision 2.1  1995/10/29  12:01:18  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:25  houghton
 * Move to Version 2.0
 *
 * Revision 1.7  1995/02/13  15:34:18  houghton
 * New functions and many enhancements to existing functions.
 *
 * Revision 1.6  1994/08/15  19:57:06  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.5  1994/08/15  19:40:18  houghton
 * Cleanup; Rating QA1 Checkin
 *
 * Revision 1.4  1994/07/26  14:37:21  houghton
 * Fix basename in Common.h
 * Fix month in Logger
 *
 * Revision 1.3  1994/07/13  13:43:00  houghton
 * Added LoggerTee function and fixed some bugs with logging
 *
 * Revision 1.2  1994/06/20  15:28:40  dpotluri
 * LibCommon Port to OPENVMS
 *
 * Revision 1.1  1994/06/17  18:07:29  houghton
 * Cool new Logger function
 *
 *
 *********************************************************************/

#include "_Common.h"
#include <stdio.h>

COMMON_VERSION(
  Logger,
  "$Id$" );


LogLevelBit	_CLogCurMesgLevel;
const char *	_CLogLocFile;
long		_CLogLocLine;

void
Logger( const char * mesgFmt, ... )
{
  
  va_list   args;

  va_start( args, mesgFmt );

  LoggerArgs( _CLogLocFile,
	      _CLogLocLine,
	      _CLogCurMesgLevel,
	      NULL,
	      mesgFmt,
	      args );

  va_end( args );
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
