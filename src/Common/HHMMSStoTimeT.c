/*********************************************************************
 *
 * Title:            HHMMSStoTimeT.c
 *
 * Description:
 *
 *	Return a time_t (long) for the time in the HHMMSS string.
 *
 * Notes:
 *
 *      This function does no bounds or error checking. It was
 *      made to translate the string with as few instructions as
 *  	possible. See TimeStringToTimeT for a more flexible translator.
 *
 * Programmer:	    Paul Houghton - (houghton@cworld)
 *
 * Start Date:	    02/19/94 12:55
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/10/29 12:01:15  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:23  houghton
 * Move to Version 2.0
 *
 * Revision 1.3  1994/08/15  19:57:04  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.2  1994/06/17  18:03:59  houghton
 * Cleanup for beta release.
 *
 * Revision 1.1  1994/06/06  13:23:35  houghton
 * Avl and DateTime functions added for Rating
 *
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  HHMMSStoTimeT,
  "$Id$" );

time_t 
HHMMSStoTimeT( const char * hhmmss )  
{
  long  timeSeconds = 0;
  
  int	hour = ( ( (hhmmss[0] - '0') * 10) + (hhmmss[1] - '0') );
  int	min = ( ( (hhmmss[2] - '0') * 10) + (hhmmss[3] - '0') );
  int	sec = ( ( (hhmmss[4] - '0') * 10) + (hhmmss[5] - '0') );

  timeSeconds = hour * SEC_PER_HOUR;
  timeSeconds += min * SEC_PER_MIN;
  timeSeconds += sec;

  return( timeSeconds );
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
