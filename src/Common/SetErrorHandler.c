/*********************************************************************
 *
 * Title:            SetErrorHandler.c
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
 * Start Date:	    01/29/94 20:26
 *
 * Modification History:
 *
 * $Log$
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";

#include <_Common.h>
#include <Common.h>

void
SetErrorHandler(
    void (*errorHandler)( CommonErrorType error, const char * mesg )
    )
{
  CommonErrorHandler_ = errorHandler;
  return;
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
