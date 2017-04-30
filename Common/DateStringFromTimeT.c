/* 1995-02-10 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"

COMMON_VERSION(
  DateStringFromTimeT,
  "$Id$" );


const char *
DateStringFromTimeT( char * buffer, const char * fmt, time_t seconds )
{
  struct tm * tmTime;

  tmTime = gmtime( &seconds );

  return( DateStringFromTm( buffer, fmt, tmTime ) );
}
