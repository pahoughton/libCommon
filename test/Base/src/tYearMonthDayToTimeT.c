/*********************************************************************
 *
 * File:        tYearMonthDayToTimeT.c
 * Project:	Common
 * Desc:
 *
 *  
 *
 * Notes:
 *
 * Author:	Paul A. Houghton - (paul.houghton@wcom.com)
 * Created:	09/24/98 06:51
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

struct TestValues
{
  int	    year;
  int	    month;
  int	    day;
  time_t    result;
};

static struct TestValues TestData[] =
{
  { 1940,   1,	1,  -946771200 },
  { 1949,  12, 31, -631238400 },
  { 1950,   1,	1,  -631152000 },
  { 1951,   1,	1,  -599616000 },
  { 1960,   1,	1,  -315619200 },
  { 1970,   1,	1,  0 },
  { 1980,   1,	1,  315532800 },
  { 1990,   1,	1,  631152000 },
  { 1990,  12,	1,  660009600 },
  { 1998,  12, 31,  915062400 },
  { 1999,  12,	1,  944006400 },
  { 1999,  12, 31,  946598400 },
  { 2000,   1,	1,  946684800 },
  { 2000,  12, 31,  978220800 },
  { 2001,   1,  1,  978307200 },
  { 2025,  12, 31,  1767139200 },

  { 50,   1,  1,  -631152000 },
  { 51,   1,  1,  -599616000 },
  { 60,   1,  1,  -315619200 },
  { 70,   1,  1,  0 },
  { 80,   1,  1,  315532800 },
  { 90,   1,  1,  631152000 },
  { 90,  12,  1,  660009600 },
  { 98,  12, 31,  915062400 },
  { 99,  12,  1,  944006400 },
  { 99,  12, 31,  946598400 },
  { 00,   1,  1,  946684800 },
  { 00,  12, 31,  978220800 },
  { 01,   1,  1,  978307200 },
  { 25,  12, 31,  1767139200 },

  { 0, 0 }
};

int
tYearMonthDayToTimeT( void )
{
  int	    ret = 1;
  int	    t;
  time_t    value;

  for( t = 0; TestData[ t ].year; ++ t )
    {
      value = YearMonthDayToTimeT( TestData[ t ].year,
				   TestData[ t ].month,
				   TestData[ t ].day );

      if( value != TestData[ t ].result )
	{
	  printf( "YearMonthDayToTimeT: FAILED\n"
		  "  got:   %ld\n"
		  "  exp:   %ld\n"
		  "  diff:  %ld\n",
		  value,
		  TestData[ t ].result,
		  value - TestData[ t ].result );
	  ret = 0;
	}
    }
  return( ret );
}

/*
 *
 * Revision Log:
 *
 * $Log$
 *
 */
