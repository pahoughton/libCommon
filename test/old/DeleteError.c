/*********************************************************************
 *
 * Title:            DeleteError.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Dora Potluri x561-6131 - (dpotluri@shoe.wiltel.com)
 *
 * Start Date:	    07/15/94 09:59
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.1  1994/08/25  15:58:48  houghton
 * Initial test program for libCommon
 *
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";

#include <stdio.h>

#include <Common.h>


#include <AvlTest.h>


void DeleteError(
    void 	*data,
    AvlVisit	order,
    void 	*closure )
{
  int *	value = (int *) data;
  
  printf("Still In the tree %d \n", *value);
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
