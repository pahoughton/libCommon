/*********************************************************************
 *
 * Title:            DateStringFromTimeT.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    02/10/95 10:16
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/10/28 19:11:41  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:17  houghton
 * Move to Version 2.0
 *
 * Revision 1.2  1995/02/20  14:22:50  houghton
 * Improve month calc. changed from a for loop
 * to an array that has the day of year for each
 * end of month.
 *
 * Revision 1.1  1995/02/13  15:34:14  houghton
 * New functions and many enhancements to existing functions.
 *
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  DateStringFromTimeT,
  "$Id$" );


const char *
DateStringFromTimeT( char * buffer, const char * fmt, time_t seconds )
{
  struct tm * tmTime;

  tmTime = gmtime( &seconds );

  return( DateStringFromTm( buffer, fmt, tmTime ) );
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
