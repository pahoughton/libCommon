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

/*
 * These constants are defined in DateTimeData.c if your linker
 * has problems finding them (MS-Win) call the LinkDateData function
 * from main.
 */

/* function in DataTimeData.c needed for some linkers */
void LinkDateData( void );  
 
extern const int    DaysInMonth[];
extern const char * Months[];
extern const char * AbbrMonths[];
extern const char * WeekDays[];
extern const char * AbbrWeekDays[];

#define IsLeapYear(_year_)  \
    ( !(_year_ % 4) && ( (_year_ % 100) || !(_year_ % 400) ) )

time_t	Difftm( struct tm * t1, struct tm * t2 );

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
 *        Copyright (c) 1994 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/
/*
 * Well actually most of it is public domain.
 */
   
