/* 1995-11-07 (cc) Paul Houghton <paul4hough@gmail.com>

   Return a string description of a CommonErrorType value.
 */

#include "_Common.h"

COMMON_VERSION(
  ErrorTypeString,
  "$Id$" );

static const char * ErrorType[] =
{
/* NONE */	"None",
/* APP */	"App",
/* OSERROR */	"OpSys",
/* COMMON */	"Common",
/* WCF */	"Wcf",
/* SYBERR */	"Syb Error",
/* SYBMSG */	"Syb Mesg",
/* SYBOC */	"Syboc",
		0
};

const char *
ErrorTypeString( CommonErrorType type )
{
  if( type < ET_NONE || type >= ET_UNDEFINED )
    return( "UNKNOWN" );
  else
    return( ErrorType[ type ] );
}
