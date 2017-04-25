/*********************************************************************
 *
 * File:        DateStringFromTm.c
 * Project:	Common
 * Desc:
 *
 *  
 *
 * Notes:
 *
 * Author:	Paul A. Houghton - (paul.houghton@wcom.com)
 * Created:	02/10/95 10:22
 *
 * Revision History: (See end of file for Revision Log)
 *
 *  Last Mod By:    $Author$
 *  Last Mod:	    $Date$
 *  Version:	    $Revision$
 *
 *********************************************************************/

#include "_Common.h"

#include <stdio.h>

COMMON_VERSION(
  DateStringFromTm,
  "$Id$");


const char *
DateStringFromTm( char * buf, const char * fmt, const struct tm * tmTime )
{
  static char 	dateString[50];

  char * str = (buf) ? buf : dateString;

  if( fmt )
    {
      strftime( str, 50, fmt, tmTime );
    }
  else
    {
      sprintf( str, "%02d/%02d/%04d %02d:%02d:%02d",
	       tmTime->tm_mon + 1,
	       tmTime->tm_mday,
	       tmTime->tm_year + 1900,
	       tmTime->tm_hour,
	       tmTime->tm_min,
	       tmTime->tm_sec );
    }
  return( str );
}

/*
 *
 * Revision Log:
 *
 * $Log$
 * Revision 2.2  1998/09/24 14:32:31  houghton
 * Changed to generate 4 digit year.
 * Cleanup.
 *
 * Revision 2.1  1995/10/28 19:11:41  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:17  houghton
 * Move to Version 2.0
 *
 * Revision 1.2  1995/02/20  14:22:51  houghton
 * Improve month calc. changed from a for loop
 * to an array that has the day of year for each
 * end of month.
 *
 * Revision 1.1  1995/02/13  15:34:14  houghton
 * New functions and many enhancements to existing functions.
 *
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
 *        Copyright (c) 1994 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/
