/*********************************************************************
 *
 * File:        tYYMMDDtoTimeT.c
 * Project:	Common
 * Desc:
 *
 *  
 *
 * Notes:
 *
 * Author:	Paul A. Houghton - (paul.houghton@wcom.com)
 * Created:	09/23/98 08:18
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
  const char *	yymmdd;
  time_t	result;
};

static struct TestValues TestData[] =
{
  /* { "400101junk", 0 }, out of range (year > 2038 */
  /* { "491231junk", 0 }, out of range (year > 2038 */
  { "500101junk", -631152000 },
  { "510101junk", -599616000 },
  { "600101junk", -315619200 },
  { "700101junk", 0 },
  { "800101junk", 315532800 },
  { "900101junk", 631152000 },
  { "901201junk", 660009600 },
  { "981231junk", 915062400 },
  { "991201junk", 944006400 },
  { "991231junk", 946598400 },
  { "000101junk", 946684800 },
  { "001231junk", 978220800 },
  { "010101junk", 978307200 },
  { "251231junk", 1767139200 },
  { 0, 0 }
};

    
int
tYYMMDDtoTimeT( void )
{
  int	    ret = 1;
  int	    t;
  time_t    value;

  struct tm ttm;
  memset( &ttm, 0, sizeof( ttm ) );
  
  for( t = 0; TestData[ t].yymmdd; ++ t )
    {
      value = YYMMDDtoTimeT( TestData[ t ].yymmdd );
      if( value != TestData[ t ].result )
	{
	  printf( "YYYYMMDDtoTimeT: FAILED\n"
		  "  string:    %s\n"
		  "  value:     %ld\n"
		  "  expected:  %ld\n"
		  "  diff:      %ld\n",
		  TestData[ t ].yymmdd,
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

	strcpy( testStr, (TestData[ t ].yymmdd[0] < '5' ? "20" : "19" ));
	strncpy( testStr + 2, TestData[ t ].yymmdd, 6 );
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

/*
 *
 * Revision Log:
 *
 * $Log$
 *
 */
