/* 1994-07-14 (cc) Dora Potluri
 */

#include <stdio.h>

#include <Common.h>

#include <AvlTest.h>

#include <LargeTestVals.h>



int AvlTestLargeValues()
{
  AvlTree testTree;
  int 	  index;
  int *	  findData;

  testTree = AvlInit( CompareNodes, NULL, NULL, NULL );

  if ( testTree == NULL )
    {
      printf(" AvlInit Failed \n" );
      return( RET_ERROR );
    }

  for ( index = 0; index < LARGE_NUM_VALS; index++ )
    {
      if ( AvlAdd( testTree, (void *) &LargeTestVals[ index ] ) != NULL )
	{
	  TestOutput("Duplicate Value: %d \n", LargeTestVals[ index ] );
	}
    }

  for ( index = 0; index < LARGE_NUM_VALS; index++ )
    {
      if ( (findData = AvlFind( testTree, (void *) &LargeTestVals[index] ) ) ==
	   NULL )
	{
	  TestOutput("Failed to find Element %d \n", LargeTestVals[ index ] );
	  return( RET_ERROR );
	}
    }

  TestOutput("Number of Elements is :%ld \n", AvlCount( testTree ) );

  for ( index =0, findData = NULL; index < LARGE_NUM_DELS; index++ )
    {
      if ((findData = AvlDel( testTree, &LargeDelVals[index] ) ) == NULL )
	{
	  TestOutput("Element:%d Not in Tree \n", LargeDelVals[index] );
	}
    }

  TestOutput("Number of Elements is :%ld \n", AvlCount( testTree ) );


  return( RET_SUCCEED );
}
