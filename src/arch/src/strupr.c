/*********************************************************************
 *
 * Title:            strupr.c
 *
 * Description:
 *
 *	Convert a string to upper case.
 *
 * Error Handling:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton (pah)
 *
 * Start Date:	    01/29/94 21:02
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.3  1994/08/15  19:57:12  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.2  1994/06/17  18:04:05  houghton
 * Cleanup for beta release.
 *
 * Revision 1.1  1994/01/31  14:06:19  houghton
 * Add avl and some other minor functions
 *
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";

#include <ctype.h>

#include "_Common.h"

char	*
strupr(
    char	*str
    )
{
  
  char	*string = str;
  
  
  while( *string != 0 )
    {
      if( islower(*string) )
	{
	  *string = toupper(*string);
	}
      string++;
    }
  return(str);
  
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

