/* 1994-02-14 (cc) Paul Houghton <paul4hough@gmail.com>
 */
#ifndef _Common_DateTime_h_
#define _Common_DateTime_h_

#ifdef __cplusplus
extern "C" {
#endif

#define SEC_PER_MIN   60
#define SEC_PER_HOUR  (60 * SEC_PER_MIN)
#define SEC_PER_DAY   (24 * SEC_PER_HOUR)
#define SEC_PER_YEAR  (365 * SEC_PER_DAY)
#define MIN_PER_HOUR  60
#include <time.h>

#if !defined( DAYOFWEEK_ENUM )
#define DAYOFWEEK_ENUM 1

typedef enum {
  Sunday = 0,
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday
} DayOfWeek;

#endif

extern const int    DaysInMonth[];
extern const int    MonthDayOfYear[];
extern const char * Months[];
extern const char * AbbrMonths[];
extern const char * WeekDays[];
extern const char * AbbrWeekDays[];

BOOL
IsLeapYear( short year );

time_t
Difftm( struct tm * t1, struct tm * t2 );

time_t
YYYYMMDDtoTimeT( const char * yymmdd );

time_t
YYMMDDtoTimeT( const char * yymmdd );

time_t
HHMMSStoTimeT( const char * hhmmss );

time_t
DateStringToTimeT( const char * dateString, const char * fmt );

const char *
DateStringFromTimeT( char * buf, const char * fmt, time_t sec );

const char *
DateStringFromTm( char * buf, const char * fmt, const struct tm * tmTime );

time_t
YearMonthDayToTimeT( int year, int month, int day );

#define HourMinSecToTimeT( hour, min, sec ) \
  ( (hour * 60 * 60 ) + (min * 60) + sec )


#if !defined( COMMON_HAVE_STRPTIME )
char *
strptime( char *buf, const char *format, struct tm *tm);
#endif


#ifdef __cplusplus
};
#endif

#endif /* ! def _DateTime_h_ */
