/* 1995-11-07 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"

COMMON_VERSION(
  _CommonErrorDesc,
  "$Id$" );

static char Desc[ 2048 ];

void
_CommonErrorDesc( const char * fmt, ... )
{
  va_list args;

  va_start( args, fmt );

  Desc[ 0 ] = 0;

  vsprintf( Desc, fmt, args );

  CommonErrDesc = Desc;
}
