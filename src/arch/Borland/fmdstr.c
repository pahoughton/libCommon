/*********************************************************************
 *
 * Title:            FileModeString.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (houghton@cworld.wiltel.com)
 *
 * Start Date:	    12/23/94 08:23
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.1  1995/10/29  18:14:02  houghton
 * First Borland Port support files
 *
 * Revision 2.1  1995/10/29  13:33:56  houghton
 * Initial Linux Build of Version 2
 *
 * Revision 2.0  1995/10/28  17:35:47  houghton
 * Move to Version 2.0
 *
 * Revision 1.1  1995/02/13  15:34:17  houghton
 * New functions and many enhancements to existing functions.
 *
 *
 *********************************************************************/
#include "_Common.h"
#include <sys/stat.h>

COMMON_VERSION(
  FileModeString,
  "$Id$");

static char ModeString[15];

const char * 
FileModeString( mode_t	mode, char * modeString )
{
    char * str = ModeString;

    if( modeString != 0 )
      {
	str = modeString;
      }

    str[0] = ( S_ISREG( mode )  ? '-' :
	       S_ISLNK( mode )  ? 'l' :
	       S_ISDIR( mode ) 	? 'd' :
	       S_ISCHR( mode ) 	? 'c' :
	       S_ISBLK( mode )	? 'b' :
	       S_ISFIFO( mode ) ? 'p' :
	       S_ISSOCK( mode ) ? 's' : '?' );

    str[1] = ( mode & S_IREAD ) ? 'r' : '-';
    str[2] = ( mode & S_IWRITE ) ? 'w' : '-';
    str[3] = ( mode & S_IEXEC ) ? 'x' : '-' ;

    str[4] = ( mode & S_IREAD ) ? 'r' : '-';
    str[5] = ( mode & S_IWRITE ) ? 'w' : '-';
    str[6] = ( mode & S_IEXEC ) ? 'x' : '-' ;

    str[7] = ( mode & S_IREAD ) ? 'r' : '-';
    str[8] = ( mode & S_IWRITE ) ? 'w' : '-';
    str[9] = ( mode & S_IEXEC ) ? 'x' : '-' ;

    str[10] = 0;

    return( str );
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
