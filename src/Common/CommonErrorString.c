/*********************************************************************
 *
 * Title:            CommonErrorString.c
 *
 * Description:
 *
 *	Translate a CommonError value into a string
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
 * Revision 2.2  1997/05/07 11:36:55  houghton
 * Cleanup
 *
 * Revision 2.1  1995/11/10 00:45:47  houghton
 * Initial Version
 *
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

  
