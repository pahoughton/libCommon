/*********************************************************************
 *
 * Title:            _CommonErrorDesc.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/07/95 11:50
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.2  1997/09/19 09:07:11  houghton
 * Changed: renamed CommonError* variables to CommonErr becuase of conflict with
 *     enum names.
 * Changed to use global public variables (CommonErr*) for error info
 *     instead of private (_CommonError*) variables.
 * Removed _CommonError* global variables.
 *
 * Revision 2.1  1995/11/10 00:56:07  houghton
 * Initial Version
 *
 *
 *********************************************************************/

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

