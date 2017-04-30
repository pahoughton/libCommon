/* 1993-12-23 (cc) Paul Houghton <paul4hough@gmail.com>
 */
#include "_Common.h"

#include <stdlib.h>
#include <string.h>

COMMON_VERSION(
  strdup,
  "$Id$");

char *
strdup( const char * input )
{
  char *    output;

  if( input == NULL ||
      (output = malloc( strlen( input ) + 1 ) ) == NULL )
    {
      return( NULL );
    }
  else
    {
      strcpy( output, input );
      return( output );
    }
}
