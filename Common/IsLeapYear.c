/* 1995-10-10 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"

COMMON_VERSION(
  IsLeapYear,
  "$Id$" );

BOOL
IsLeapYear( int year )
{
  return( !(year % 4) && ( (year % 100) || !(year % 400) ) );
}
