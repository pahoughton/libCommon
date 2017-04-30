/* 1994-08-04 (cc) Paul Houghton <paul4hough@gmail.com>
 */
/* 1994-02-18 (cc) paul4hough@gmail.com
   Remove leading and trailing spaces from a string.
*/
#include "_Common.h"
#include <string.h>

void
StripChar( char * buffer, char c )
{
  char * beg = buffer;
  size_t len;

  for(; *beg && *beg == c; ++ beg );

  len = strlen(beg);
  for( ; beg[len-1] == c; --len );

  if( beg != buffer ) {
    memmove( buffer, beg, len );
  }
  buffer[len] = 0;
}

void
StripChars( char * buffer, const char * chars )
{
  char * beg = buffer + strspn( buffer, chars );
  size_t len = strlen(beg);
  for( ; len && strchr( chars, beg[len-1] ); --len );
  if( beg != buffer ) {
    memmove( buffer, beg, len );
  }
  buffer[len] = 0;
}
