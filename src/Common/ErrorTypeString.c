/*********************************************************************
 *
 * Title:            ErrorTypeString.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/07/95 11:13
 *
 * Modification History:
 *
 * $Log$
 *
 *********************************************************************/

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



		
