/*********************************************************************
 *
 * File:        YYYYMMDDtoTimeT.c
 * Project:	Common
 * Desc:
 *
 *  Convert a YYYYMMDD string (i.e. 19980403) to a time_t (seconds
 *  since 1/1/1970) value.
 *
 * Notes:
 *
 *  NO ERROR CHECKING or validation of the string is performed. If
 *  an invalid string is passed the results are undefined.
 *
 * Author:	Paul A. Houghton - (paul.houghton@wcom.com)
 * Created:	02/03/95 08:05
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
  YYYYMMDDtoTimeT,
  "$Id$");

time_t 
YYYYMMDDtoTimeT( const char * yyyymmdd )
{
  int   year = ( ((yyyymmdd[0] - '0') * 1000 )
		 + ((yyyymmdd[1] - '0') * 100)
		 + ((yyyymmdd[2] - '0') * 10)
		 + ((yyyymmdd[3] - '0' )) );
  int	month = ( ( (yyyymmdd[4] - '0') * 10)
		  + (yyyymmdd[5] - '0') );
  int	day = ( ( (yyyymmdd[6] - '0') * 10)
		+ (yyyymmdd[7] - '0') );

  return( YearMonthDayToTimeT( year, month, day ) );
}

/*
 *
 * Revision Log:
 *
 * $Log$
 * Revision 2.3  1998/09/22 14:34:54  houghton
 * Changed: this function used to convert 0098 to 1998, this
 *     functionallity was not documented and is nolonger supported.
 *
 * Revision 2.2  1995/10/29 18:16:01  houghton
 * Fixes for Borland 4.0 Port
 *
 * Revision 2.1  1995/10/29  12:01:26  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:36  houghton
 * Move to Version 2.0
 *
 * Revision 1.1  1995/02/13  15:34:22  houghton
 * New functions and many enhancements to existing functions.
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
 *        Copyright (c) 1994 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/

