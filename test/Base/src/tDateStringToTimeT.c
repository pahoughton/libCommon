/*********************************************************************
 *
 * File:        tDateStringToTimeT.c
 * Project:	Common
 * Desc:
 *
 *  
 *
 * Notes:
 *
 * Author:	Paul A. Houghton - (paul.houghton@wcom.com)
 * Created:	09/24/98 05:08
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
  const char *	str;
  const char *	fmt;
  time_t	result;
};

static struct TestValues TestData[] =
{
  { "1/1/1940 5:23:49",	    0,			    -946771200 + 19429 },
  { "01/01/1940",	    0,			    -946771200 },
  { "12/31/1949",	    0,			    -631238400 },
  { "1/1/1950",		    0,			    -631152000 },
  { "1/1/1951",		    0,			    -599616000 },
  { "1/1/1960 14:50",	    0,			    -315619200 + 53400 },
  { "1/1/1970",		    0,			    0 },
  { "1/1/1980 23:59:59",    0,			    315532800 + 86399},
  { "1/1/1990",		    0,			    631152000 },
  { "12/1/1990",	    0,			    660009600 },
  { "12/31/1998",	    0,			    915062400 },
  { "12/1/1999",	    0,			    944006400 },
  { "12/31/1999 22:00",	    0,			    946598400 + 79200 },
  { "1/1/2000 10:00:04",    0,			    946684800 + 36004 },
  { "12/31/2000",	    0,			    978220800 },
  { "1/1/2001",		    0,			    978307200 },
  { "12/31/2025",	    0,			    1767139200 },

  { "1/1/50",		    0,			    -631152000 },
  { "1/1/51",		    0,			    -599616000 },
  { "1/1/60 14:50",	    0,			    -315619200 + 53400 },
  { "1/1/70",		    0,			    0 },
  { "1/1/80 23:59:59",	    0,			    315532800 + 86399},
  { "1/1/90",		    0,			    631152000 },
  { "12/1/90",		    0,			    660009600 },
  { "12/31/98",		    0,			    915062400 },
  { "12/1/99",		    0,			    944006400 },
  { "12/31/99 22:00",	    0,			    946598400 + 79200 },
  { "1/1/00 10:00:04",	    0,			    946684800 + 36004 },
  { "12/31/00",		    0,			    978220800 },
  { "1/1/01",		    0,			    978307200 },
  { "12/31/25",		    0,			    1767139200 },

  { "1/1/1950",		    "%m/%d/%Y",		    -631152000 },
  { "1/1/1960 14:50",	    "%m/%d/%Y %H:%M",	    -315619200 + 53400 },
  { "1/1/1970",		    "%m/%d/%Y",		    0 },
  { "1/1/1980 23:59:59",    "%m/%d/%Y %H:%M:%S",    315532800 + 86399},
  { "12/31/1999 22:00",	    "%m/%d/%Y %H:%M",	    946598400 + 79200 },
  { "1/1/2000 10:00:04",    "%m/%d/%Y %H:%M:%S",    946684800 + 36004 },
  
  { "1/1/50",		    "%m/%d/%y",		    -631152000 },
  { "1/1/60 14:50",	    "%m/%d/%y %H:%M",	    -315619200 + 53400 },
  { "1/1/70",		    "%m/%d/%y",		    0 },
  { "1/1/80 23:59:59",	    "%m/%d/%y %H:%M:%S",    315532800 + 86399},
  { "12/31/99 22:00",	    "%m/%d/%y %H:%M",	    946598400 + 79200 },
  { "1/1/00 10:00:04",	    "%m/%d/%y %H:%M:%S",    946684800 + 36004 },
  
  { 0, 0 }
};

int
tDateStringToTimeT( void )
{
  int	    ret = 1;
  int	    t;
  time_t    value;

  struct tm ttm;
  memset( &ttm, 0, sizeof( ttm ) );
  
  for( t = 0; TestData[ t].str; ++ t )
    {
      value = DateStringToTimeT( TestData[ t ].str,
				 TestData[ t ].fmt );
      if( value != TestData[ t ].result )
	{
	  printf( "DateStringToTimeT: FAILED\n"
		  "  str:       %s\n"
		  "  fmt:       %s\n"
		  "  value:     %ld\n"
		  "  expected:  %ld\n"
		  "  diff:      %ld\n",
		  TestData[ t ].str,
		  TestData[ t ].fmt ? TestData[ t ].fmt : "(none)",
		  value,
		  TestData[ t ].result,
		  value - TestData[ t ].result );
	  printf( "\nexp: %s", asctime( gmtime( &TestData[ t ].result ) ) );
	  printf( "got: %s\n", asctime( gmtime( &value ) ) );
	  ret = 0;
	}
#if defined( DEBUG )
      else
	{
	  printf( "DateStringToTimeT: passed\n"
		  "  str:       %s\n"
		  "  fmt:       %s\n"
		  "  value:     %ld\n",
		  TestData[ t ].str,
		  TestData[ t ].fmt ? TestData[ t ].fmt : "(none)",
		  value );
	  printf( "%s\n", asctime( gmtime( &value ) ) );
	}
#endif
      
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
