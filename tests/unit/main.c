/* 1998-09-16 (cc) paul4hough@gmail.com
 */

#include "proto.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TestFunct
{
  const char *	name;
  int		(*funct)( void );
};

struct TestFunct    Tests[] =
{
  { "Common",               tCommon },
  { "strptime",		    tstrptime },
  { "CenterLine",           tCenterLine },
  { "StripChars",           tStripChars },
  { "StringTo",		    tStringTo },
  { "CanExecute",           tCanExecute },
  { "MemberOfGroup",        tMemberOfGroup },
  { "FindPath",             tFindPath },

  /*
  { "IsLeapYear",	    tIsLeapYear },
  { "YearMonthDayToTimeT",  tYearMonthDayToTimeT },
  { "HourMinSecToTimeT",    tHourMinSecToTimeT },
  { "YYYYMMDDtoTimeT",	    tYYYYMMDDtoTimeT },
  { "YYMMDDtoTimeT",	    tYYMMDDtoTimeT },
  { "HHMMSStoTimeT",	    tHHMMSStoTimeT },
  { "DateStringToTimeT",    tDateStringToTimeT },
  { "DateStringFromTm",	    tDateStringFromTm },
  { "DateStringFromTimeT",  tDateStringFromTimeT },
  */
  {0, 0},
};

int
main( int argc, char * argv[] )
{
  int result = 0;

  if( argc > 1 )
    {
      int t;
      int tested;

      for( t = 1; t < argc; ++ t )
	{
	  int f;

	  tested = 0;
	  for( f = 0; Tests[ f ].name; ++ f )
	    {
	      if( strcmp( argv[ t ], Tests[ f ].name ) == 0 )
		{
		  tested = 1;
		  if( ! Tests[f].funct() )
		    {
		      printf( "%s failed!\n", Tests[f].name );
		      exit( 1 );
		    }
		  else
		    {
		      printf( "%s passed.\n", Tests[f].name );
		    }
		}
	    }
	  if( ! tested )
	    {
	      printf( "no test available for %s\n",
		      argv[t] );
	      exit( 1 );
	    }
	}
    }
  else
    {
      int f;
      for( f = 0; Tests[ f ].name; ++ f )
	{
	  if( ! Tests[f].funct() )
	    {
	      printf( "%s failed!\n", Tests[f].name );
	      exit( 1 );
	    }
	  else
	    {
	      printf( "%s passed.\n", Tests[f].name );
	    }
	}
    }

  return( result );
}
