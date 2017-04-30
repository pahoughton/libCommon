/* 1994-02-11 (cc) Paul Houghton <paul4hough@gmail.com>

 	Return a time_t (long) for the time in the HHMMSS string.

       This function does no bounds or error checking. It was
       made to translate the string with as few instructions as
   	possible. See TimeStringToTimeT for a more flexible translator.

*/

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
