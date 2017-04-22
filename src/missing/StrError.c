/*********************************************************************
 *
 * Title:            StrError.c
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
 * Start Date:	    09/03/93 12:17
 *
 * Modification History:
 *
 *
 *********************************************************************/
static char SccsId[] = {"%W% %G% %U%"};

#include <stdio.h>

#include "_Common.h"

char            *ErrFile = NULL;
int             ErrLine = 0;
int             OsErr = 0;
CommonErrorType    Errno = E_NONE;







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
