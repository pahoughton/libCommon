/* 1998-09-23 (cc) Paul A. Houghton <paul4hough@gmail.com>
 */


#include "TestConfig.h"
#include "TestFunctProto.h"
#include "Common.h"

#include <time.h>
#include <stdio.h>

struct TestValues
{
  const char *	yyyymmdd;
  time_t	result;
};

static struct TestValues TestData[] =
{
  { "19400101junk", -946771200 },
  { "19491231junk", -631238400 },
  { "19500101junk", -631152000 },
  { "19510101junk", -599616000 },
  { "19600101junk", -315619200 },
  { "19700101junk", 0 },
  { "19800101junk", 315532800 },
  { "19900101junk", 631152000 },
  { "19901201junk", 660009600 },
  { "19981231junk", 915062400 },
  { "19991201junk", 944006400 },
  { "19991231junk", 946598400 },
  { "20000101junk", 946684800 },
  { "20001231junk", 978220800 },
  { "20010101junk", 978307200 },
  { "20251231junk", 1767139200 },
  { 0, 0 }
};


int
tYYYYMMDDtoTimeT( void )
{
  int	    ret = 1;
  int	    t;
  time_t    value;

  struct tm ttm;
  memset( &ttm, 0, sizeof( ttm ) );

  for( t = 0; TestData[ t].yyyymmdd; ++ t )
    {
      value = YYYYMMDDtoTimeT( TestData[ t ].yyyymmdd );
      if( value != TestData[ t ].result )
	{
	  printf( "YYYYMMDDtoTimeT: FAILED\n"
		  "  value:     %ld\n"
		  "  expected:  %ld\n"
		  "  diff:      %ld\n",
		  value,
		  TestData[ t ].result,
		  value - TestData[ t ].result );
	  ret = 0;
	}
      /* Double check */
      {
	char	    checkStr[ 128 ];
	char	    testStr[ 128 ];
	struct tm   checkTm;
	memcpy( &checkTm, gmtime( &value ), sizeof( checkTm ) );

	sprintf( checkStr,
		 "%04d%02d%02d %02d%02d%02d",
		 checkTm.tm_year + 1900,
		 checkTm.tm_mon + 1,
		 checkTm.tm_mday,
		 checkTm.tm_hour,
		 checkTm.tm_min,
		 checkTm.tm_sec );
	strncpy( testStr, TestData[ t ].yyyymmdd, 8 );
	testStr[8] = 0;
	strcat( testStr, " 000000" );
	if( strcmp( checkStr, testStr ) )
	  {
	    printf( "YYYYMMDDtoTimeT: FAILED: %s != %s\n",
		    testStr, checkStr );
	  }
      }
    }
  return( ret );
}
