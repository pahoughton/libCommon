/*********************************************************************
 *
 * File:        tstrptime.c
 * Project:	Common
 * Desc:
 *
 *  
 *
 * Notes:
 *
 * Author:	Paul A. Houghton - (paul.houghton@wcom.com)
 * Created:	09/16/98 10:23
 *
 * Revision History: (See end of file for Revision Log)
 *
 *  Last Mod By:    $Author$
 *  Last Mod:	    $Date$
 *  Version:	    $Revision$
 *
 *********************************************************************/

#define _XOPEN_SOURCE

#include "TestFunctProto.h"

#include <time.h>
#include <stdio.h>

static
int
fail(
  const char *	    str,
  const struct tm * tm
  )
{
  printf( "strptime Failed - %s\n"
	  "  tm_year:   %d\n"
	  "  tm_mon:    %d\n"
	  "  tm_mday:   %d\n"
	  "  tm_hour:   %d\n"
	  "  tm_min:    %d\n"
	  "  tm_sec:    %d\n",
	  str,
	  (*tm).tm_year,
	  (*tm).tm_mon,
	  (*tm).tm_mday,
	  (*tm).tm_hour,
	  (*tm).tm_min,
	  (*tm).tm_sec );
  return( 0 );
}

static
int
test(
  char *	    testStr,
  const char *	    fmt,
  const struct tm * testTm
  )
{
    char	    checkStr[128];
    struct tm	    checkTm;

    memset( &checkTm, 0, sizeof( checkTm ) );
    
    if( ! strptime( testStr, fmt, &checkTm ) )
      {
	printf( "strptime - conv failed for %s fmt: %s\n",
		testStr, fmt );
	return( 0 );
      }

    strftime( checkStr, sizeof( checkStr ), "%m/%d/%Y %H:%M:%S", &checkTm );

    if( memcmp( testTm, &checkTm, sizeof( checkTm ) ) )
      {
	return( fail( testStr, &checkTm ) );
      }
    
    printf( "strptime - %s -> %s\n", testStr, checkStr );
    
    return( 1 );
}

int
tstrptime( void )
{

  {
    char *	    testStr = (char *)"04/28/1945 13:04:40";
    const char *    fmt = "%m/%d/%Y %H:%M:%S";
    struct tm	    testTm = { 40, 4, 13, 28, 3, 45, 0, 0, 0, 0, 0 };

    if( ! test( testStr, fmt, &testTm ) )
      return( 0 );
  }
  
  {
    char *	    testStr = (char *)"04/28/2025 13:04:40";
    const char *    fmt = "%m/%d/%Y %H:%M:%S";
    struct tm	    testTm = { 40, 4, 13, 28, 3, 125, 0, 0, 0, 0, 0 };

    if( ! test( testStr, fmt, &testTm ) )
      return( 0 );
  }
  
  {
    char *	    testStr = (char *)"04/28/25 13:04:40";
    const char *    fmt = "%m/%d/%y %H:%M:%S";
    struct tm	    testTm = { 40, 4, 13, 28, 3, 125, 0, 0, 0, 0, 0 };

    if( ! test( testStr, fmt, &testTm ) )
      return( 0 );
  }
  
  {
    char *	    testStr = (char *)"04/28/1945 00:04:40";
    const char *    fmt = "%m/%d/%Y %H:%M:%S";
    struct tm	    testTm = { 40, 4, 0, 28, 3, 45, 0, 0, 0, 0, 0 };

    if( ! test( testStr, fmt, &testTm ) )
      return( 0 );
  }
  
  {
    char *	    testStr = (char *)"04/28/25 10:04:40 PM";
    const char *    fmt = "%m/%d/%y %I:%M:%S %p";
    struct tm	    testTm = { 40, 4, 22, 28, 3, 125, 0, 0, 0, 0, 0 };

    if( ! test( testStr, fmt, &testTm ) )
      return( 0 );
  }
  
  {
    char *	    testStr = (char *)"04/28/25 1:04:40 AM";
    const char *    fmt = "%m/%d/%y %I:%M:%S %p";
    struct tm	    testTm = { 40, 4, 1, 28, 3, 125, 0, 0, 0, 0, 0 };

    if( ! test( testStr, fmt, &testTm ) )
      return( 0 );
  }
  
  {
    char *	    testStr = (char *)"04/28/25 12:04:40 PM";
    const char *    fmt = "%m/%d/%y %I:%M:%S %p";
    struct tm	    testTm = { 40, 4, 12, 28, 3, 125, 0, 0, 0, 0, 0 };

    if( ! test( testStr, fmt, &testTm ) )
      return( 0 );
  }
  
  {
    char *	    testStr = (char *)"04/28/25 12:04:40 AM";
    const char *    fmt = "%m/%d/%y %I:%M:%S %p";
    struct tm	    testTm = { 40, 4, 0, 28, 3, 125, 0, 0, 0, 0, 0 };

    if( ! test( testStr, fmt, &testTm ) )
      return( 0 );
  }
  
    
  return( 1 );
}

/*
 *
 * Revision Log:
 *
 * $Log$
 *
 */
