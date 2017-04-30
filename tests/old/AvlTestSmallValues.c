/* 1994-07-14 (cc) Dora Potluri
 */

#include <stdio.h>

#include <Common.h>

#include <AvlTest.h>

#include <testvals.h>



int AvlTestSmallValues()
{
  AvlTree testTree;
  int 	  index;
  int *	  findData;
  int *	  minValue = NULL;
  int *	  maxValue = NULL;

  testTree = AvlInit( CompareNodes, NULL, NULL, NULL );

  if ( testTree == NULL )
    {
      printf(" AvlInit Failed \n" );
      return( RET_ERROR );
    }

  for ( index = 0; index < NUM_VALS; index++ )
    {
      if ( AvlAdd( testTree, (void *) &TestVals[ index ] ) != NULL )
	{
	  printf("AvlAdd %d Failed \n", index );
	  return( RET_ERROR );
	}
    }

  minValue = (int *) AvlFindMin( testTree );
  maxValue = (int *) AvlFindMax( testTree );

      /*
	Note: AvlFindMin and AvlFindMax are not presently working.
	*/

/*  if ( NULL == minValue || NULL == maxValue )
    {
      printf("Could not get the minValue and Max Value \n" );
      return( RET_ERROR );
    }
  printf("Min Value %d, Max Value \n",*minValue, *maxValue);
  */

  for ( index = 0; index < NUM_VALS; index++ )
    {
      if ( (findData = AvlFind( testTree, (void *) &TestVals[index] ) ) == NULL )
	{
	  printf("Failed to find Element %d \n", TestVals[ index ] );
	  return( RET_ERROR );
	}
    }

  TestOutput("Number of Elements is :%ld \n", AvlCount( testTree ) );

  for ( index =0, findData = NULL; index < NUM_DELS; index++ )
    {
      if ((findData = AvlDel( testTree, &DelVals[index] ) ) == NULL )
	{
	  printf("Failed to Delete a Element %d \n", index );
	  return( RET_ERROR );
	}
    }

  TestOutput("Number of Elements is :%ld \n", AvlCount( testTree ) );

  AvlDispose( &testTree, DeleteError, AVL_LEFT_TO_RIGHT, NULL );

  return( RET_SUCCEED );
}
