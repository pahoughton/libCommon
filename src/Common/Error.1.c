/*********************************************************************
 *
 * Title:            Error.c
 *
 * Description:
 *
 *	
 *
 * Error Handling:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton (pah)
 *
 * Start Date:	    09/03/93 12:35
 *
 * Modification History:
 *
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include <_Common.h>
#include <Common.h>


int
Error( const char * message )
{
  fprintf( stderr, "Common Lib Error: %d - %s\n",
	   Errno, message );
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
