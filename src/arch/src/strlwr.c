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
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";

#include <ctype.h>

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



