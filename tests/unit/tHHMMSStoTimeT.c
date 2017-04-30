/* 1998-09-23 (cc) Paul A. Houghton <paul4hough@gmail.com>
 */

#include "TestConfig.h"
#include "TestFunctProto.h"
#include "Common.h"

#include <time.h>
#include <stdio.h>


int
tHHMMSStoTimeT( void )
{
  int	    ret = 1;

  char	    testStr[ 128 ];

  time_t    hour;
  time_t    min;
  time_t    sec;
  time_t    value;
  time_t    expect;

  for( hour = 0; hour < 23; ++ hour )
    {
      for( min = 0; min < 59; ++ min )
	{
	  for( sec = 0; sec < 59; ++ sec )
	    {
	      sprintf( testStr, "%02ld%02ld%02ldjunk",
		       hour,
		       min,
		       sec );

	      value = HHMMSStoTimeT( testStr );

	      expect = ( sec
			 + ( min * 60 )
			 + ( hour * 60 * 60 ) );

	      if( value != expect )
		{
		  printf( "HHMMSStoTimeT: FAILED - exp: %ld  is: %ld\n",
			  expect,
			  value );
		  ret = 0;
		}
	    }
	}
    }
  return( ret );
}
