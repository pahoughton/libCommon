/*********************************************************************
 *
 * Title:            DateStringFromTm.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    02/10/95 10:22
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.1  1995/02/13  15:34:14  houghton
 * New functions and many enhancements to existing functions.
 *
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";

#include <DateTime.h>

#include <stdio.h>

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
      sprintf( str, "%02d/%02d/%02d %02d:%02d:%02d",
	       tmTime->tm_mon + 1,
	       tmTime->tm_mday,
	       tmTime->tm_year,
	       tmTime->tm_hour,
	       tmTime->tm_min,
	       tmTime->tm_sec );
    }
  return( str );
}






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
