/*********************************************************************
 *
 * Title:            YYYYMMDDtoTimeT.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    02/03/95 08:05
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.1  1995/02/13  15:34:22  houghton
 * New functions and many enhancements to existing functions.
 *
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";

#include "_Common.h"

time_t 
YYYYMMDDtoTimeT( const char * yyyymmdd )
{
  int   year = 0;
  int	month = ( ( (yyyymmdd[4] - '0') * 10) + (yyyymmdd[5] - '0') );
  int	day = ( ( (yyyymmdd[6] - '0') * 10) + (yyyymmdd[7] - '0') );

  if( yyyymmdd[0] != '0' )
    {
      year = ( ((yyyymmdd[0] - '0') * 1000 ) + ((yyyymmdd[1] - '0') * 100) +
	       ((yyyymmdd[2] - '0') * 10) + ((yyyymmdd[3] - '0' )) );
    }
  else
    {
      year = ((yyyymmdd[2] - '0') * 10) + ((yyyymmdd[3] - '0' ));
    }

  return( YearMonthDayToTimeT( year, month, day ) );
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
