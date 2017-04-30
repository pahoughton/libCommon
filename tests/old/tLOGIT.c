/* 1995-11-21 (cc) Paul A. Houghton - (paul.houghton@wcom.com)
 */


#include <Common.h>


BOOL
tLOGIT( void )
{
  LOGIT( LOG_ERROR, ("Test LOGIT LOG_ERROR %d\n",1 ) );

  LOGIT( LOG_TEST, ("BAD BAD BAD\n" ));

  return( TRUE );
}
