/* 1995-02-10 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"

#include <stdio.h>

COMMON_VERSION(
  DateStringFromTm,
  "$Id$");


const char *
DateStringFromTm( char * buf, const char * fmt, const struct tm * tmTime )
{
  static char 	dateString[50];

  char * str = (buf) ? buf : dateString;

  if( fmt )
    {
      strftime( str, 50, fmt, tmTime );
    }
  else
    {
      sprintf( str, "%02d/%02d/%04d %02d:%02d:%02d",
	       tmTime->tm_mon + 1,
	       tmTime->tm_mday,
	       tmTime->tm_year + 1900,
	       tmTime->tm_hour,
	       tmTime->tm_min,
	       tmTime->tm_sec );
    }
  return( str );
}
