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
 * Revision 1.1  1994/08/25  15:58:52  houghton
 * Initial test program for libCommon
 *
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";

#include <stdio.h>

#include <Common.h>

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
