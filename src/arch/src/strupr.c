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
 * Revision 2.0  1995/10/28  17:35:50  houghton
 * Move to Version 2.0
 *
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

#include "_Common.h"
#include <ctype.h>

COMMON_VERSION(
  strupr,
  "$Id$");

char *
strupr(char * str )
{
  
  char * string;

  for( string = str; *string != 0; string++ )
    {
      if( islower(*string) )
	*string = toupper(*string);
    }
  
  return(str);
  
}
