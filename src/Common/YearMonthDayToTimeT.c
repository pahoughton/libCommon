/*********************************************************************
 *
 * Title:            YearMonthDayToTimeT.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    11/03/94 08:35
 *
 * Modification History:
 *
 * $Log$
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";

#include <DateTime.h>
#include <time.h>

time_t
YearMonthDayToTimeT(
  int	    year,
  int 	    month,
  int 	    day
  )
{
  long  seconds = 0;
  int	leapCount = 0;
  int   index = 0;

  /* I really don't like putting this test in here, but
   * it's is the only valid solution to being passed
   * all 0 values. If I get all 0 the i should return
   * 0.
   */

  if( ! year && ! month && ! day ) /* everything is 0 */
    {
      return( 0 );
    }
  
  if( year > 1900 )
    {
      year = year - 1900;
    }
  else
    {
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
