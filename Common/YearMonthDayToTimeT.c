/* 1994-11-03 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"
#include <stdlib.h>

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

  if( year >= 0 )
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
