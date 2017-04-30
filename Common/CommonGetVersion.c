/* 1997-04-26 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"

COMMON_VERSION(
  CommonGetVersion,
  "$Id$" );


const long CommonLibVersion = COMMON_LIB_VERSION;

const char CommonVersion[] = "@(#) libCommon - 3.01.01";

#endif

const char *
CommonGetVersion( void )
{
  return( CommonVersion );
}
