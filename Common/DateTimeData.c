/* 1994-02-19 (cc) Paul Houghton <paul4hough@gmail.com>

   This is a collection of constants used by date manipulation
   functions.
*/

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
