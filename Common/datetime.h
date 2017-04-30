/* 1994-08-04 (cc) Paul Houghton <paul4hough@gmail.com>
 */
#ifndef _missing_datetime_h_
#define _missing_datetime_h_
/* 1993-09-03 (cc) paul4hough@gmail.com
 */
#include <missing/missing.h>
#include <time.h>

/**************************************************************
 * D A T E / T I M E   P r o c e s s i n g
 **************************************************************/

#define SEC_PER_MIN   60
#define SEC_PER_HOUR  (60 * SEC_PER_MIN)
#define SEC_PER_DAY   (24 * SEC_PER_HOUR)
#define SEC_PER_YEAR  (365 * SEC_PER_DAY)
#define MIN_PER_HOUR  60
#define MIN_TIMET     LONG_MIN
#define MAX_TIMET     LONG_MAX
#define MIN_YEAR      (1970 + (MIN_TIMET / SEC_PER_YEAR))
#define MAX_YEAR      (1970 + (MAX_TIMET / SEC_PER_YEAR))

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

/*
 * These constants are defined in DateTimeData.c if your linker
 * has problems finding them (MS-Win) call the LinkDateData function
 * from main.
 */

/* function in DataTimeData.c needed for some linkers */
void LinkDateData( void );

#if ! defined( COMMON_DATETIME_VALUES )
#define COMMON_DATETIME_VALUES 1
extern const int    DaysInMonth[];
extern const int    DaysInMonthLeap[];
extern const int    MonthDayOfYear[];
extern const int    MonthDayOfYearLeap[];
extern const char * Months[];
extern const char * AbbrMonths[];
extern const char * WeekDays[];
extern const char * AbbrWeekDays[];
#endif

#if !defined(IsLeapYear)
#define IsLeapYear( _yr_ ) (!(_yr_ % 4) && ( (_yr_ % 100) || !(_yr_ % 400) ) )
#endif

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

#endif /* ! _missing_datetime_h_ */
