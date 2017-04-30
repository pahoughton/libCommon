/* 1994-08-04 (cc) Paul Houghton <paul4hough@gmail.com>

   Convert a YYYYMMDD string (i.e. 19980403) to a time_t (seconds
   since 1/1/1970) value.

   NO ERROR CHECKING or validation of the string is performed. If
   an invalid string is passed the results are undefined.
 */

#include "_Common.h"

COMMON_VERSION(
  YYYYMMDDtoTimeT,
  "$Id$");

time_t
YYYYMMDDtoTimeT( const char * yyyymmdd )
{
  int   year = ( ((yyyymmdd[0] - '0') * 1000 )
		 + ((yyyymmdd[1] - '0') * 100)
		 + ((yyyymmdd[2] - '0') * 10)
		 + ((yyyymmdd[3] - '0' )) );
  int	month = ( ( (yyyymmdd[4] - '0') * 10)
		  + (yyyymmdd[5] - '0') );
  int	day = ( ( (yyyymmdd[6] - '0') * 10)
		+ (yyyymmdd[7] - '0') );

  return( YearMonthDayToTimeT( year, month, day ) );
}
