#ifndef _DateTime_h_
#define _DateTime_h_
/*********************************************************************
 *
 * Title:            DateTime.h
 *
 * Description:
 *
 *  Misc date time manipulation functions
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe)
 *
 * Start Date:	    02/14/94 08:33
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.0  1995/10/28  17:35:19  houghton
 * Move to Version 2.0
 *
 * Revision 1.4  1995/02/13  15:34:15  houghton
 * New functions and many enhancements to existing functions.
 *
 * Revision 1.3  1994/06/20  10:27:19  houghton
 * Porting and add LoggerLoc function
 *
 * Revision 1.2  1994/06/17  18:03:57  houghton
 * Cleanup for beta release.
 *
 * Revision 1.1  1994/06/06  13:23:34  houghton
 * Avl and DateTime functions added for Rating
 *
 *
 *********************************************************************/

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

/*
 * These constants are defined in DateTimeData.c if your linker
 * has problems finding them (MS-Win) call the LinkDateData function
 * from main.
 */

/* function in DataTimeData.c needed for some linkers */
void LinkDateData( void );  
 
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

    
  
#ifdef __cplusplus
};
#endif

#endif /* ! def _DateTime_h_ */

/**
 *             This software is the sole property of
 *
 *                 The Williams Companies, Inc.
 *                       1 Williams Center
 *                         P.O. Box 2400
 *                      Tulsa, Oklahoma 74102
 *
 *        Copyright (c) 1994 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/
/*
 * Well actually most of it is public domain.
 */
   
