/*********************************************************************
 *
 * Title:            DateTimeData.c
 *
 * Description:
 *
 *  This is a collection of constants used by date manipulation
 *  functions.
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (houghton@cworld)
 *
 * Start Date:	    02/19/94 12:57
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.2  1995/10/30 14:55:14  houghton
 * Move contents of Bit.h & DateTime.h to Common.h
 * Add Net2Host
 *
 * Revision 2.1  1995/10/28  19:11:43  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:19  houghton
 * Move to Version 2.0
 *
 * Revision 1.5  1995/02/13  15:34:15  houghton
 * New functions and many enhancements to existing functions.
 *
 * Revision 1.4  1994/08/15  19:57:00  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.3  1994/06/20  15:28:39  dpotluri
 * LibCommon Port to OPENVMS
 *
 * Revision 1.2  1994/06/17  18:03:58  houghton
 * Cleanup for beta release.
 *
 * Revision 1.1  1994/06/06  13:23:35  houghton
 * Avl and DateTime functions added for Rating
 *
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  DateTimeData,
  "$Id$");

const int DaysInMonth[] =
{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0};

const int DaysInMonthLeap[] =
{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0};

const int MonthDayOfYear[] =
{ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365, 0};

const int MonthDayOfYearLeap[] =
{ 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366, 0};

const char * Months[] =
{
  "January", "February", "March", "April", "May", "June",
  "July", "August", "September", "October", "November", "December",
  NULL
};

const char * AbbrMonths[] =
{
  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
  NULL
};

const char * WeekDays[] =
{
  "Sunday", "Monday", "Tuesday", "Wednesday",
  "Thursday", "Friday", "Saturday",
  NULL
};

const char * AbbrWeekDays[] =
{
  "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat",
  NULL
};


/* stupid function that forces some linkers to load this object file
 */

void LinkDateData( void )
{
  return;
}

/*
 * Public Domain - no copyright
 */
