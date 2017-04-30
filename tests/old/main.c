/* 1994-07-15 (cc) Dora Potluri
 */

#include <Common.h>
#include <stdio.h>

#include "_t_Proto.h"


BOOL tTempFileName( void );

struct TestEnt
{
  const char *	name;
  BOOL		(* funct)( void );
};

struct TestEnt Tests[] =
{
  { "Error",		tCommonError },
  { "LOGIT",		tLOGIT },
  { "TempFileName",	tTempFileName },
  { NULL, NULL }
};


int
main( int argc, char * argv[] )
{
  size_t test;

  for( test = 0; Tests[ test ].name != NULL; test++ )
    {
      fprintf( stderr, "Testing: %s ", Tests[ test ].name );

      if( ! Tests[ test ].funct() )
	{
	  fprintf( stderr, "FAILED\n" );
	  return( 1 );
	}
      else
	{
	  fprintf( stderr, "passed\n" );
	}
    }

  fprintf( stderr, "%s\n\nTested\n",CommonGetVersion() );

  return( 0 );
}

#if defined( OLD_TEST )

#include "AvlTest.h"

int main(
    int 	argc,
    char     *argv[] )
{

  TestOutputInit("LibCommonTestResults.log" );

  if ( AvlTestSmallValues() != RET_SUCCEED )
    {
      printf("Failed to Test Small Values  \n" );
      return( RET_ERROR );
    }

  if ( AvlTestLargeValues() != RET_SUCCEED )
    {
      printf("Failed to Test Large Values \n" );
      return( RET_ERROR );
    }

  if ( DateTimeTest(argc, argv) != RET_SUCCEED )
    {
      printf("Failed to test Date Time \n" );
      return( RET_ERROR );
    }

  if ( StringTest() != RET_SUCCEED )
    {
      printf("Failed to test the String Functions \n" );
      return( RET_ERROR );
    }

  return( RET_SUCCEED );
}

#endif
