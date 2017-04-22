/*********************************************************************
 *
 * File:        YYMMDDtoTimeT.c
 * Project:	Common
 * Desc:
 *
 *  Convert a YYMMDD string (i.e. 980403) to a time_t (seconds
 *  since 1/1/1970) value.
 *
 *  If the year part is >= 50 the century is traslated as 1900. If
 *  the year is < 50 the century is traslated as 2000 (see
 *  YearMonthDayToTimeT.c
 *
 * Notes:
 *
 *  NO ERROR CHECKING or validation of the string is performed. If
 *  an invalid string is passed the results are undefined.
 *
 * Author:	Paul A. Houghton - (paul.houghton@wcom.com)
 * Created:	02/19/94 13:07
 *
 * Revision History: (See end of file for Revision Log)
 *
 *  Last Mod By:    $Author$
 *  Last Mod:	    $Date$
 *  Version:	    $Revision$
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  YYMMDDtoTimeT,
  "$Id$");

 
time_t 
YYMMDDtoTimeT( const char * yymmdd )
{
  int	year = ( ( (yymmdd[0] - '0') * 10) + (yymmdd[1] - '0') );
  int	month = ( ( (yymmdd[2] - '0') * 10) + (yymmdd[3] - '0') );
  int	day = ( ( (yymmdd[4] - '0') * 10) + (yymmdd[5] - '0') );

  return( YearMonthDayToTimeT( year, month, day ) );
}


/*
 *
 * Revision Log:
 *
 * $Log$
 * Revision 2.2  1998/09/24 14:33:30  houghton
 * Cleanup.
 *
 * Revision 2.1  1995/10/29 12:01:26  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:35  houghton
 * Move to Version 2.0
 *
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
 */

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
