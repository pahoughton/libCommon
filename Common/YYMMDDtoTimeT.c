/* 1994-02-19 (cc) Paul Houghton <paul4hough@gmail.com>

   Convert a YYMMDD string (i.e. 980403) to a time_t (seconds
   since 1/1/1970) value.

   If the year part is >= 50 the century is traslated as 1900. If
   the year is < 50 the century is traslated as 2000 (see
   YearMonthDayToTimeT.c

   NO ERROR CHECKING or validation of the string is performed. If
   an invalid string is passed the results are undefined.
*/

#include "_Common.h"

COMMON_VERSION(
  YYMMDDtoTimeT,
  "$Id$");


time_t
YYMMDDtoTimeT( const char * yymmdd )
{
  int	year = ( ( (yymmdd[0] - '0') * 10) + (yymmdd[1] - '0') );
  int	month = ( ( (yymmdd[2] - '0') * 10) + (yymmdd[3] - '0') );
  int	day = ( ( (yymmdd[4] - '0') * 10) + (yymmdd[5] - '0') );

  return( YearMonthDayToTimeT( year, month, day ) );
}
