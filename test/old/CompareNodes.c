/*********************************************************************
 *
 * Title:            CompareNodes.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Dora Potluri x561-6131 - (dpotluri@shoe.wiltel.com)
 *
 * Start Date:	    07/15/94 09:13
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.1  1994/08/25  15:58:47  houghton
 * Initial test program for libCommon
 *
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";


#include <stdio.h>
#include <Common.h>


#include <AvlTest.h>

int CompareNodes(
    void * 	dataOne,
    void * 	dataTwo,
    AvlNodeType nd )
{

  
  return ( *( (int* ) dataOne) - *((int *) dataTwo) );
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
