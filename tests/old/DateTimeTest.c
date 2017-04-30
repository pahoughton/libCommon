/* 1994-07-18 (cc) Dora Potluri
 */

#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <sys/time.h>

#include <Common.h>

#include <AvlTest.h>

Ret_Status
DateTimeTest(
    int 	argc,
    char *	argv[] )
{
  int 		leapYear;
  char 		*yearBuffer=NULL;
  char 		*hourBuffer= NULL;
  time_t	testTime;
  time_t	presentTime;

  if ( ArgEnvInt( &argc, argv, "dat", "DATETIME", 0, INT_MAX, &leapYear )
       != RET_SUCCEED )
    {
      printf("Failed to Get  year from Environment \n" );
      return( RET_ERROR );
    }

  /*
    Check the leap year
    */

  if ( IsLeapYear( leapYear ) == TRUE )
    {
      TestOutput("Year:%ld Is Leap Year \n", leapYear );
    }
  else
    {
      TestOutput("Year:%ld Is NOT Leap Year \n", leapYear );
    }

      /*
	Test the YYMMDDtoTimeT
	*/
   if ( ArgEnvString( &argc, argv, "year", "YEAR", &yearBuffer )
       != RET_SUCCEED )
    {
      printf("Failed to get the year from Environment \n" );
      return( RET_ERROR );
    }


  testTime = YYMMDDtoTimeT( yearBuffer );

  TestOutput("%s is Converted to %s \n",
	     yearBuffer, asctime( gmtime( &testTime ) ) );

  if ( ArgEnvString( &argc, argv, "hour", "HOUR", &hourBuffer )
       != RET_SUCCEED )
    {
      printf("Failed to get Hour from Environment \n" );
      return( RET_ERROR );
    }

  presentTime = HHMMSStoTimeT( hourBuffer );

  testTime = testTime + presentTime;
  TestOutput("%s:%s is Converted to %s \n",
	 yearBuffer,hourBuffer, asctime( gmtime( &testTime ) ) );

  return( RET_SUCCEED );
}
