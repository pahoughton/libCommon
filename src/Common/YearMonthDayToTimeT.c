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
  
  /* I really don't like putting this test in here, but
   * it's is the only valid solution to being passed
   * all 0 values. If I get all 0 the i should return
   * 0.
   */

  if( ! year && ! month && ! day ) /* everything is 0 */
    {
      return( 0 );
    }
  
  if( year >= 1900 )
    {
      year = year - 1900;
    }
  else
    {
      /* FIXME_2100
       * this is my year 2000 fix it assumes 2 digit years < 50 mean
       * 20xx. There must be a better solution. I should probably get
       * the current system time and use it for a hint at the value
       * to use.
       */
      if( year < 50 )
	{
	  year = year + 100;
	}
    }

  leapCount = ((year - 70) + 2) / 4;

  if( IsLeapYear( year ) )
    {
      leapCount--;
    }
  
  seconds = ((year - 70) * SEC_PER_YEAR) + (leapCount * SEC_PER_DAY );

  seconds += SEC_PER_DAY * MonthDayOfYear[ month - 1 ];
  
  if( IsLeapYear( year ) && month > 2 )
    {
      seconds += SEC_PER_DAY;
    }

  day--;
  
  seconds += SEC_PER_DAY * day;

  return( seconds );
}

/*
 *
 * Revision Log:
 *
 * $Log$
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
