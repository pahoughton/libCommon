/*********************************************************************
 *
 * Title:            AvlTestLargeValues.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Dora Potluri x561-6131 - (dpotluri@shoe.wiltel.com)
 *
 * Start Date:	    07/14/94 13:21
 *
 * Modification History:
 *
 * $Log$
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";

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
