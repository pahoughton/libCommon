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

#include "TestConfig.h"
#include "TestFunctProto.h"
#include "Common.h"

#include <time.h>
#include <stdio.h>

#define TEST_DATE( fmt, str, year, mon, mday, hour, min, sec )		      \
{									      \
  char		testStr[128];						      \
  struct tm	testTm;							      \
  									      \
  strcpy( testStr, str );						      \
  memset( &testTm, 0, sizeof( testTm ) );				      \
  testTm.tm_year    = ( year - 1900 );					      \
  testTm.tm_mon	    = mon - 1;						      \
  testTm.tm_mday    = mday;						      \
  testTm.tm_hour    = hour;						      \
  testTm.tm_min	    = min;						      \
  testTm.tm_sec	    = sec;						      \
									      \
  if( ! test( fmt, testStr, &testTm, __LINE__ ) )			      \
    return( 0 );							      \
}

static
int
fail(
  const char *	    str,
  const struct tm * checkTm,
  const struct tm * testTm,
  long		    sourceLine
  )
{
  printf( "strptime: %ld FAILED: %s\n"
	  "              exp    was\n"
	  "  tm_year:   %4d   %4d %c\n"
	  "  tm_mon:      %2d     %2d %c\n"
	  "  tm_mday:     %2d     %2d %c\n"
	  "  tm_hour:     %2d     %2d %c\n"
	  "  tm_min:      %2d     %2d %c\n"
	  "  tm_sec:      %2d     %2d %c\n",
	  sourceLine,
	  str,
	  (*checkTm).tm_year, (*testTm).tm_year ,
	  (*checkTm).tm_year != (*testTm).tm_year ? '*' : ' ',
	  (*checkTm).tm_mon,  (*testTm).tm_mon,
	  (*checkTm).tm_mon != (*testTm).tm_mon ? '*' : ' ',
	  (*checkTm).tm_mday, (*testTm).tm_mday,
	  (*checkTm).tm_mday != (*testTm).tm_mday ? '*' : ' ',
	  (*checkTm).tm_hour, (*testTm).tm_hour,
	  (*checkTm).tm_hour != (*testTm).tm_hour ? '*' : ' ',
	  (*checkTm).tm_min,  (*testTm).tm_min,
	  (*checkTm).tm_min != (*testTm).tm_min ? '*' : ' ',
	  (*checkTm).tm_sec,  (*testTm).tm_sec,
	  (*checkTm).tm_sec != (*testTm).tm_sec ? '*' : ' ' );
  return( 0 );
}

static
int
test(
  const char *	    fmt,
  char *	    testStr,
  const struct tm * testTm,
  long		    sourceLine
  )
{
#if defined( DEBUG )
    char	    checkStr[128];
#endif
    struct tm	    checkTm;

    memset( &checkTm, 0, sizeof( checkTm ) );
    
    if( ! strptime( testStr, fmt, &checkTm ) )
      {
	printf( "strptime - conv failed for %s fmt: %s\n",
		testStr,
		fmt );
	return( 0 );
      }

    if( memcmp( testTm, &checkTm, sizeof( checkTm ) ) )
      return( fail( testStr, &checkTm, testTm, sourceLine ) );

#if defined( DEBUG )
    strftime( checkStr, sizeof( checkStr ), "%m/%d/%Y %H:%M:%S", &checkTm );
    printf( "strptime - %s -> %s\n", testStr, checkStr );
#endif
    
    return( 1 );
}

int
tstrptime( void )
{

  TEST_DATE( "%m/%d/%Y %H:%M:%S",
	     "04/28/1945 13:04:40",
	     1945,
	     4,
	     28,
	     13,
	     04,
	     40 );

  TEST_DATE( "%m/%d/%Y %H:%M:%S",
	     "04/28/1950 13:04:40",
	     1950,
	     4,
	     28,
	     13,
	     04,
	     40 );

  TEST_DATE( "%m/%d/%Y %H:%M:%S",
	     "12/31/1999 13:04:40",
	     1999,
	     12,
	     31,
	     13,
	     04,
	     40 );

  TEST_DATE( "%m/%d/%Y %H:%M:%S",
	     "01/1/2000 13:04:40",
	     2000,
	     1,
	     1,
	     13,
	     04,
	     40 );

  TEST_DATE( "%m/%d/%Y %H:%M:%S",
	     "12/1/2001 13:04:40",
	     2001,
	     12,
	     1,
	     13,
	     04,
	     40 );

  TEST_DATE( "%m/%d/%Y %H:%M:%S",
	     "01/1/2025 13:04:40",
	     2025,
	     1,
	     1,
	     13,
	     04,
	     40 );

  TEST_DATE( "%m/%d/%y %H:%M:%S",
	     "04/28/45 13:04:40",
	     2045,
	     4,
	     28,
	     13,
	     04,
	     40 );

  TEST_DATE( "%m/%d/%y %H:%M:%S",
	     "04/28/50 13:04:40",
	     1950,
	     4,
	     28,
	     13,
	     04,
	     40 );

  TEST_DATE( "%m/%d/%y %H:%M:%S",
	     "12/31/99 13:04:40",
	     1999,
	     12,
	     31,
	     13,
	     04,
	     40 );

  TEST_DATE( "%m/%d/%y %H:%M:%S",
	     "01/1/00 13:04:40",
	     2000,
	     1,
	     1,
	     13,
	     04,
	     40 );

  TEST_DATE( "%m/%d/%y %H:%M:%S",
	     "12/1/01 13:04:40",
	     2001,
	     12,
	     1,
	     13,
	     04,
	     40 );

  TEST_DATE( "%m/%d/%y %H:%M:%S",
	     "01/1/25 13:04:40",
	     2025,
	     1,
	     1,
	     13,
	     04,
	     40 );

  TEST_DATE( "%y%m%d",
	     "980228",
	     1998,
	     2,
	     28,
	     0, 0, 0 );
  
  TEST_DATE( "%y%m%d",
	     "000228",
	     2000,
	     2,
	     28,
	     0, 0, 0 );
  
  TEST_DATE( "%y%m%d",
	     "010228",
	     2001,
	     2,
	     28,
	     0, 0, 0 );

  TEST_DATE( "%Y%m%d",
	     "19490101",
	     1949,
	     1,
	     1,
	     0, 0, 0 );
  
  TEST_DATE( "%m/%d/%y %I:%M:%S %p",
	     "04/28/25 10:04:40 PM",
	     2025,
	     4,
	     28,
	     22,
	     4,
	     40 );
  
  TEST_DATE( "%m/%d/%y %I:%M:%S %p",
	     "04/28/25 1:04:40 AM",
	     2025,
	     4,
	     28,
	     1,
	     4,
	     40 );
  
  TEST_DATE( "%m/%d/%y %I:%M:%S %p",
	     "04/28/25 12:04:40 PM",
	     2025,
	     4,
	     28,
	     12,
	     4,
	     40 );
  
  TEST_DATE( "%m/%d/%y %I:%M:%S %p",
	     "04/28/25 12:04:40 AM",
	     2025,
	     4,
	     28,
	     0,
	     4,
	     40 );
  
  return( 1 );
}

/*
 *
 * Revision Log:
 *
 * $Log$
 * Revision 1.1  1998/09/22 14:39:41  houghton
 * Initial version.
 *
 *
 */
