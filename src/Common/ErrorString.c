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
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";

#include <Common.h>

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
 
  if( error < 0 || error > C_EUNDEFINED )
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
