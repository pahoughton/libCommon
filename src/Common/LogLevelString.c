/*********************************************************************
 *
 * Title:            LogLevelString.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (houghton@cworld.wiltel.com)
 *
 * Start Date:	    07/18/94 12:36
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.0  1995/10/28  17:35:25  houghton
 * Move to Version 2.0
 *
 * Revision 1.2  1994/08/15  19:57:05  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.1  1994/06/17  18:07:28  houghton
 * Cool new Logger function
 *
 *
 *********************************************************************/
#include "_Common.h"

COMMON_VERSION(
  LogLevelString,
  "$Id$");


extern char * LogLevelNames[];

const char *
LogLevelString(
    LogBit lvl
    )
{

  if( lvl == LOG_NONE )  return( LogLevelNames[0] );
  if( lvl == LOG_ERROR ) return( LogLevelNames[1] );
  if( lvl == LOG_WARN )  return( LogLevelNames[2] );
  if( lvl == LOG_USR1 )  return( LogLevelNames[3] );
  if( lvl == LOG_USR2 )  return( LogLevelNames[4] );
  if( lvl == LOG_INFO )  return( LogLevelNames[5] );
  if( lvl == LOG_TEST )  return( LogLevelNames[6] );
  if( lvl == LOG_DEBUG ) return( LogLevelNames[7] );
  if( lvl == LOG_FUNCT ) return( LogLevelNames[8] );
  if( lvl == LOG_ALL )   return( LogLevelNames[9] );

  return( "UNKNOWN" );

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
