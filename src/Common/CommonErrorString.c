/*********************************************************************
 *
 * Title:            CommonErrorString.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/07/95 11:18
 *
 * Modification History:
 *
 * $Log$
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  CommonErrorString,
  "$Id$" );

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

  
