/* 1995-11-07 (cc) paul4hough@gmail.com

   Translate a CommonError value into a string
*/

#include "_Common.h"

static const char * ErrorString[] =
{
  /* NONE */	    "none",
  /* BADPARAM */    "bad parameter",
  /* RANGE */	    "out of range",
		    0
};

const char *
CommonErrorString( CommonError err )
{
  if( err < EC_NONE || err >= EC_UNDEFINED )
    return( "UNKNOWN" );
  else
    return( ErrorString[ err ] );
}
