/*********************************************************************
 *
 * Title:            strlwr.c
 *
 * Description:
 *
 * 	convert a string to lower case
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
 * Start Date:	    01/29/94 21:02
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.3  1994/06/17  18:04:05  houghton
 * Cleanup for beta release.
 *
 * Revision 1.2  1994/01/31  14:06:19  houghton
 * Add avl and some other minor functions
 *
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";

#include <ctype.h>

#include "_Common.h"

char *
strlwr(
    char	*str
    )
{
  
  char	*string = str;
  
  
  while( *string != 0 )
    {
      if( isupper(*string) )
	{
	  *string = tolower(*string);
	}
      string++;
    }
  return(str);
  
}



