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
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";
#if defined( AIX )
#define _ALL_SOURCE
#include <sys/mode.h>
#endif


#include <Common.h>
#include <sys/stat.h>

static char ModeString[15];

const char * 
FileModeString( umode_t	mode, char * modeString )
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

    str[1] = ( mode & S_IRUSR ) ? 'r' : '-';
    str[2] = ( mode & S_IWUSR ) ? 'w' : '-';
    str[3] = ( ( mode & S_IXUSR ) ?
	       ( mode & S_ISUID ) ? 's' : 'x' :
	       ( mode & S_ISUID ) ? 'S' : '-' );

    str[4] = ( mode & S_IRGRP ) ? 'r' : '-';
    str[5] = ( mode & S_IWGRP ) ? 'w' : '-';
    str[6] = ( ( mode & S_IXGRP ) ?
	       ( mode & S_ISGID ) ? 's' : 'x' :
	       ( mode & S_ISGID ) ? 'S' : '-' );


    str[7] = ( mode & S_IROTH ) ? 'r' : '-';
    str[8] = ( mode & S_IWOTH ) ? 'w' : '-';
    str[9] = ( mode & S_IXOTH ) ? 'x' : '-';

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
