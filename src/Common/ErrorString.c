/*********************************************************************
 *
 * Title:            ErrorString.c
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
 * Start Date:	    01/29/94 20:28
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.0  1995/10/28  17:35:21  houghton
 * Move to Version 2.0
 *
 * Revision 1.4  1995/02/13  15:34:16  houghton
 * New functions and many enhancements to existing functions.
 *
 * Revision 1.3  1994/08/15  19:57:01  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.2  1994/06/17  18:03:58  houghton
 * Cleanup for beta release.
 *
 * Revision 1.1  1994/01/31  14:06:14  houghton
 * Add avl and some other minor functions
 *
 *
 *********************************************************************/
#include "_Common.h"

#include <stdio.h>

COMMON_VERSION(
  ErrorString,
  "$Id$");

static char * ErrorDescription[] =
{
/* C_ENONE */	     "No error",
/* C_EOSERROR */     "OS error",
/* C_ERANGE */       "Value out of range",
/* C_EBADPARAM */    "Bad parameter",
/* C_EAPP */	     "Application error"
};

static char UnknownString[100];

const char *
ErrorString( CommonErrorType error )
{
 
  if( error > C_EUNDEFINED )
    {
      sprintf( UnknownString, "Unknown Error: %d", error );
      return( UnknownString );
    }
  else
    {
      return( ErrorDescription[ error ] );
    }
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
