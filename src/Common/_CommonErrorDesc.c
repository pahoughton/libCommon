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

