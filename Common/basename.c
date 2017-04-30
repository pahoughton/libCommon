/* 1995-01-28 (cc) Paul Houghton <paul4hough@gmail.com>
 * This software was swiped from the gnu code
 */
#include "_Common.h"

COMMON_VERSION(
  basename,
  "$Id$");


const char *
basename( const char * name )
{
  const char * base;

  if( ( base = strrchr( name, COMMON_DIR_SEP_CHAR ) ) != 0)
    return( base + 1 );
  else
    return( name );
}
