/*********************************************************************
 *
 * Title:            DateTimeData.c
 *
 * Description:
 *
 *	
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
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";

#include <DateTime.h>

const int DaysInMonth[] =
{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0};

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


