/*********************************************************************
 *
 * Title:            DateStringToTimeT.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    11/02/94 16:00
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.3  1995/10/29 18:15:59  houghton
 * Fixes for Borland 4.0 Port
 *
 * Revision 2.2  1995/10/29  13:33:42  houghton
 * Initial Linux Build of Version 2
 *
 * Revision 2.1  1995/10/28  19:11:42  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:18  houghton
 * Move to Version 2.0
 *
 * Revision 1.1  1995/02/13  15:34:15  houghton
 * New functions and many enhancements to existing functions.
 *
 *
 *********************************************************************/

#if defined( Sun5 )
#define __EXTENSIONS__
#endif

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
    {
      return( 0 );
    }

  if( fmt )
    {
      struct tm     tm;
      strptime( (char *)dateString, fmt, &tm );

      seconds = YearMonthDayToTimeT( tm.tm_year,
				     tm.tm_mon + 1,
				     tm.tm_mday );

      seconds += HourMinSecToTimeT( tm.tm_hour,
				    tm.tm_min,
				    tm.tm_sec );
      return( seconds );
    }

  if( (end = strchr( start, '/' ) ) == 0 )
    {
      return( 0 );
    }

  month = StringToInt( start, 10, (end - start) );

  if( month < 1 || month > 12 )
    {
      return( 0 );
    }

  start = end + 1;

  if( (end = strchr( start, '/') ) == 0 )
    {
      return( 0 );
    }

  day = StringToInt( start, 10, (end - start)  );

  if( day < 1 || day > 31 )
    {
      return( 0 );
    }

  start = end + 1;

  for( end = start; isdigit( *end ); end++ );

  year = StringToInt( start, 10, (end - start) );

  seconds = YearMonthDayToTimeT( year, month, day );
        
  for( start = end; ! isdigit( *start ) && *start != 0; start++ );

  if( *start == 0 )
    {
      return( seconds );
    }

  if( (end = strchr( start, ':' ) ) == 0 )
    {
      return( 0 );
    }

  seconds += StringToInt( start, 10, (end - start) ) * SEC_PER_HOUR;

  start = end + 1;

  for( end++ ; isdigit( *end ); end++ );

  if( end == start )
    {
      return( 0 );
    }

  seconds += StringToInt( start, 10, (end - start) ) * SEC_PER_MIN;

  if( *end != ':' )
    {
      return( seconds );
    }

  start = end + 1;

  for( end++; isdigit( *end ); end++ );

  seconds += StringToInt( start, 10, (end - start) );

  return( seconds );
}


  
  
  







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
