/* 1991-10-14 (cc) paul4hough@gmail.com
 */
#include "_Common.h"

#include <string.h>

char * CenterLine( char * dest, const char * src,int width)
{
  size_t    pad;
  size_t    srcLen = strlen( src );

  if( width < 0 || ((size_t)width) < srcLen )
    {
      pad = 0;
    }
  else
    {
      pad = ((size_t)width) - srcLen;
      pad /=2;
    }

  memset(dest,' ',pad);
  dest[pad] = 0;
  strcat(dest,src);
  return( dest );
}
