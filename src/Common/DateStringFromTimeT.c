/*********************************************************************
 *
 * Title:            DateStringFromTimeT.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    02/10/95 10:16
 *
 * Modification History:
 *
 * $Log$
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";

#include <DateTime.h>

const char *
DateStringFromTimeT( char * buffer, char * fmt, time_t seconds )
{
  struct tm * tmTime;

  tmTime = gmtime( &seconds );

  return( DateStringFromTm( buffer, fmt, tmTime ) );
}	   
      







/**
 *             This software is the sole property of
 *
 *                 The Williams Companies, Inc.
 *                       1 Williams Center
 *                         P.O. Box 2400
 *                      Tulsa, Oklahoma 74102
 *
 *        Copyright (c) 1994 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/
