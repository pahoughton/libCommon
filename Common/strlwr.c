/* 1994-01-29 (cc) Paul Houghton <paul4hough@gmail.com>
 */
#include "_Common.h"
#include <ctype.h>

COMMON_VERSION(
  strlwr,
  "$Id$");


char *
strlwr(char * str )
{

  char * string;

  for( string = str; *string != 0; string++ )
    {
      if( isupper(*string) )
	*string = tolower(*string);
    }

  return(str);

}
