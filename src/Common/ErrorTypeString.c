/*********************************************************************
 *
 * Title:            ErrorTypeString.c
 *
 * Description:
 *
 *	Return a string description of a CommonErrorType value.
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
 * Revision 2.1  1995/11/10 00:48:34  houghton
 * Initial Version
 *
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



		
