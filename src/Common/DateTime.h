#ifndef _DateTime_h_
#define _DateTime_h_
/*********************************************************************
 *
 * Title:            DateTime.h
 *
 * Description:
 *
 *
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
 *
 *********************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
  
#define SEC_PER_MIN   60
#define SEC_PER_HOUR  (60 * SEC_PER_MIN)
#define SEC_PER_DAY   (24 * SEC_PER_HOUR)
#define SEC_PER_YEAR  (365 * SEC_PER_DAY)

#include <time.h>

typedef enum {
  SUNDAY = 0,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY
} DayOfWeek;


extern const int    DaysInMonth[];
extern const char * Months[];
extern const char * AbbrMonths[];
extern const char * WeekDays[];
extern const char * AbbrWeekDays[];

#define IsLeapYear(_year_)  \
    ( !(_year_ % 4) && ( (_year_ % 100) || !(_year_ % 400) ) )


time_t
YYMMDDtoTimeT( const char * yymmdd );

time_t
HHMMSStoTimeT( const char * hhmmss );

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
 *        Copyright (c) 1993 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/
