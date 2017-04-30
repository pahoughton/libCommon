/* 1994-01-29 (cc) Paul Houghton <paul4hough@gmail.com>
 */

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
