/*********************************************************************
 *
 * Title:            YYMMDDtoTimeT.c
 *
 * Description:
 *
 *   	Convert a YYMMDD string to a time_t value. 
 *
 * Notes:
 *
 *      This function does minimal bounds and error checking. It was
 *      made to translate the string with as few instructions as
 *  	possible. See TimeStringToTimeT for a more flexible translator.
 *
 * Programmer:	    Paul Houghton - (houghton@cworld)
 *
 * Start Date:	    02/19/94 13:07
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.4  1995/02/13  15:34:22  houghton
 * New functions and many enhancements to existing functions.
 *
 * Revision 1.3  1994/08/15  19:57:10  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.2  1994/06/17  18:04:03  houghton
 * Cleanup for beta release.
 *
 * Revision 1.1  1994/06/06  13:23:38  houghton
 * Avl and DateTime functions added for Rating
 *
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";

#include <time.h>
#include <DateTime.h>

 
time_t 
YYMMDDtoTimeT( const char * yymmdd )
{
  int	year = ( ( (yymmdd[0] - '0') * 10) + (yymmdd[1] - '0') );
  int	month = ( ( (yymmdd[2] - '0') * 10) + (yymmdd[3] - '0') );
  int	day = ( ( (yymmdd[4] - '0') * 10) + (yymmdd[5] - '0') );

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
 *        Copyright (c) 1993 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/
