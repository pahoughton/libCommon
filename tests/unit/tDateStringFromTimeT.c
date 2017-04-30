/* 1998-09-24 (cc) Paul A. Houghton <paul4hough@gmail.com>
 */

#include "TestConfig.h"
#include "TestFunctProto.h"
#include "Common.h"

#include <time.h>
#include <stdio.h>

struct TestValues
{
  const char *	str;
  const char *	fmt;
  time_t	value;
};

static struct TestValues TestData[] =
{
  { "01/01/1940 05:23:49",  0,			    -946771200 + 19429 },
  { "01/01/1940 00:00:00",  0,			    -946771200 },
  { "12/31/1949 00:00:00",  0,			    -631238400 },
  { "01/01/1950 00:00:00",  0,			    -631152000 },
  { "01/01/1951 00:00:00",  0,			    -599616000 },
  { "01/01/1960 14:50:00",  0,			    -315619200 + 53400 },
  { "01/01/1970 00:00:00",  0,			    0 },
  { "01/01/1980 23:59:59",  0,			    315532800 + 86399},
  { "01/01/1990 00:00:00",  0,			    631152000 },
  { "12/01/1990 00:00:00",  0,			    660009600 },
  { "12/31/1998 00:00:00",  0,			    915062400 },
  { "12/01/1999 00:00:00",  0,			    944006400 },
  { "12/31/1999 22:00:00",  0,			    946598400 + 79200 },
  { "01/01/2000 10:00:04",  0,			    946684800 + 36004 },
  { "12/31/2000 00:00:00",  0,			    978220800 },
  { "01/01/2001 00:00:00",  0,			    978307200 },
  { "12/31/2025 00:00:00",  0,			    1767139200 },

#if defined( FIXME )
  { "1/1/1950",		    "%m/%d/%Y",		    -631152000 },
  { "1/1/1960 14:50",	    "%m/%d/%Y %H:%M",	    -315619200 + 53400 },
  { "1/1/1970",		    "%m/%d/%Y",		    0 },
  { "1/1/1980 23:59:59",    "%m/%d/%Y %H:%M:%S",    315532800 + 86399},
  { "12/31/1999 22:00",	    "%m/%d/%Y %H:%M",	    946598400 + 79200 },
  { "1/1/2000 10:00:04",    "%m/%d/%Y %H:%M:%S",    946684800 + 36004 },
#else
  { "01/01/1950",	    "%m/%d/%Y",		    -631152000 },
  { "01/01/1960 14:50",	    "%m/%d/%Y %H:%M",	    -315619200 + 53400 },
  { "01/01/1970",	    "%m/%d/%Y",		    0 },
  { "01/01/1980 23:59:59",  "%m/%d/%Y %H:%M:%S",    315532800 + 86399},
  { "12/31/1999 22:00",	    "%m/%d/%Y %H:%M",	    946598400 + 79200 },
  { "01/01/2000 10:00:04",  "%m/%d/%Y %H:%M:%S",    946684800 + 36004 },
#endif
  { 0, 0 }
};

int
tDateStringFromTimeT( void )
{
  int		ret = 1;
  int		t;
  char		value[ 128 ];
  const char *	ptr;

  for( t = 0; TestData[ t ].str; ++ t )
    {
      ptr = DateStringFromTimeT( 0, TestData[ t ].fmt, TestData[ t ].value );

      if( strcmp( ptr, TestData[ t ].str ) )
	{
	  printf( "DateStringFromTimeT: FAILED\n"
		  "  got:  %s\n"
		  "  exp:  %s\n",
		  ptr,
		  TestData[ t ].str );
	  ret = 0;
	}

      ptr = DateStringFromTimeT( value,
				 TestData[ t ].fmt,
				 TestData[ t ].value );

      if( ptr != value || strcmp( value, TestData[ t ].str ) )
	{
	  printf( "DateStringFromTimeT: FAILED\n"
		  "  got:  %s\n"
		  "  exp:  %s\n",
		  ptr,
		  TestData[ t ].str );
	  ret = 0;
	}
    }

  return( ret );
}
