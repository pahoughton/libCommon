/*********************************************************************
 *
 * Title:            main.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Dora Potluri x561-6131 - (dpotluri@shoe.wiltel.com)
 *
 * Start Date:	    07/15/94 10:01
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/11/10  01:05:48  houghton
 * *** empty log message ***
 *
 * Revision 2.0  1995/10/28  17:35:59  houghton
 * Move to Version 2.0
 *
 * Revision 1.1  1994/08/25  15:58:52  houghton
 * Initial test program for libCommon
 *
 *
 *********************************************************************/

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





/**
 *             This software is the sole property of
 *
 *                 The Williams Companies, Inc.
 *                       1 Williams Center
 *                         P.O. Box 2400
 *                      Tulsa, Oklahoma 74102
 *
 *        Copyright (c) 1993 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/
