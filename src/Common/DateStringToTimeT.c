/*********************************************************************
 *
 * File:        DateStringToTimeT.c
 * Project:	Common
 * Desc:
 *
 *  
 *
 * Notes:
 *
 * Author:	Paul A. Houghton - (paul.houghton@wcom.com)
 * Created:	11/02/94 16:00
 *
 * Revision History: (See end of file for Revision Log)
 *
 *  Last Mod By:    $Author$
 *  Last Mod:	    $Date$
 *  Version:	    $Revision$
 *
 *********************************************************************/

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

/*
 *
 * Revision Log:
 *
 * $Log$
 * Revision 2.5  1998/03/02 22:32:49  houghton
 * Bug-Fix: when passing tm.tm_year to YearMonthDayToTimeT need to add
 *     1900 to the value.
 *
 * Revision 2.4  1997/09/02 21:34:07  houghton
 * Port(Sun5): Added define _EXTENTIONS_
 *
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
 */

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
