/*********************************************************************
 *
 * File:        YearMonthDayToTimeT.c
 * Project:	Common
 * Desc:
 *
 *  
 *
 * Notes:
 *
 * Author:	Paul Houghton - (paul.houghton@wcom.com)
 * Created:	11/03/94 08:35
 *
 * Revision History: (See end of file for Revision Log)
 *
 *  Last Mod By:    $Author$
 *  Last Mod:	    $Date$
 *  Version:	    $Revision$
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  YearMonthDayToTimeT,
  "$Id$");


time_t
YearMonthDayToTimeT(
  int	    year,
  int 	    month,
  int 	    day
  )
{
  long  seconds = 0;
  int	leapCount = 0;
  
  if( year )
    {
      /* this is a best guess for 2 digit years */
      if( year > 100 )
	year = year;
      else
	year = 1900 + ( year < 50 ? year + 100 : year );

      /*
       * safty valve - if year is out of range, use min/max 
       * posible time_t value
       */
      if( year > MAX_YEAR )
	return( MAX_TIMET );
      else
	if( year < MIN_YEAR )
	  return( MIN_TIMET );
      
		
      /*
       * 1972 was a leap year
       * leap years are every 4 years except centuries unless the centruy
       * is divisable by 400 (i.e. 1600 & 2000 are leap years and
       * 1700, 1800, 1900 are not leap years).
       */ 
      leapCount = ( ((abs( year - 1970 ) + 2) / 4)
		    - (abs( year - 1900 ) / 100)
		    );

      leapCount += ( ( year < 2000  ?
			abs( year - 2000 ) / 400 :
			abs( year - 1600 ) / 400 ));

      if( IsLeapYear( year ) && year > 1970 )
	-- leapCount;
      
      if( year < 1970 )
	leapCount *= -1;
      
      seconds = ((year - 1970) * SEC_PER_YEAR) + (leapCount * SEC_PER_DAY);
      
    }

  if( month )
    {
      seconds += SEC_PER_DAY * MonthDayOfYear[ month - 1 ];
      
      if( IsLeapYear( year ) && month > 2 )
	{
	  seconds += SEC_PER_DAY;
	}
    }

  if( day )
    {
      day--;
  
      seconds += SEC_PER_DAY * day;
    }

  return( seconds );
}

/*
 *
 * Revision Log:
 *
 * $Log$
 * Revision 2.2  1997/08/20 10:39:05  houghton
 * Bug-Fix: if year was 1900 it was being treated as a two digit year.
 *
 * Revision 2.1  1995/10/29 12:01:27  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:36  houghton
 * Move to Version 2.0
 *
 * Revision 1.2  1995/02/20  14:22:51  houghton
 * Improve month calc. changed from a for loop
 * to an array that has the day of year for each
 * end of month.
 *
 * Revision 1.1  1995/02/13  15:34:23  houghton
 * New functions and many enhancements to existing functions.
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
