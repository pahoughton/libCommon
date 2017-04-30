/* 1994-11-02 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"

#include <time.h>
#include <string.h>
#include <ctype.h>

COMMON_VERSION(
  DateStringToTimeT,
  "$Id$");

time_t
DateStringToTimeT( const char * dateString, const char * fmt )
{
  const char * start = dateString;
  const char * end = 0;

  int year;
  int month;
  int day;

  time_t seconds = 0;


  if( dateString == NULL )
    return( TIMET_MIN );

  if( fmt )
    {
      struct tm     tm;

      memset( &tm, 0, sizeof( tm ) );

      if( ! strptime( (char *)dateString, fmt, &tm ) )
	return( TIMET_MIN );

      seconds = YearMonthDayToTimeT( tm.tm_year + 1900,
				     tm.tm_mon + 1,
				     tm.tm_mday );

      seconds += HourMinSecToTimeT( tm.tm_hour,
				    tm.tm_min,
				    tm.tm_sec );
      return( seconds );
    }

  if( (end = strchr( start, '/' ) ) == 0 )
    return( TIMET_MIN );

  month = StringToInt( start, 10, (end - start) );

  if( month < 1 || month > 12 )
    return( TIMET_MIN );

  start = end + 1;

  if( (end = strchr( start, '/') ) == 0 )
    return( TIMET_MIN );

  day = StringToInt( start, 10, (end - start)  );

  if( day < 1 || day > 31 )
    return( TIMET_MIN );

  start = end + 1;

  for( end = start; isdigit( *end ); end++ );

  year = StringToInt( start, 10, (end - start) );

  seconds = YearMonthDayToTimeT( year, month, day );

  for( start = end; ! isdigit( *start ) && *start != 0; start++ );

  if( *start == 0 )
    return( seconds );

  if( (end = strchr( start, ':' ) ) == 0 )
    return( TIMET_MIN );

  seconds += StringToInt( start, 10, (end - start) ) * SEC_PER_HOUR;

  start = end + 1;

  for( end++ ; isdigit( *end ); end++ );

  if( end == start )
    return( TIMET_MIN );

  seconds += StringToInt( start, 10, (end - start) ) * SEC_PER_MIN;

  if( *end != ':' )
    return( seconds );

  start = end + 1;

  for( end++; isdigit( *end ); end++ );

  seconds += StringToInt( start, 10, (end - start) );

  return( seconds );
}
