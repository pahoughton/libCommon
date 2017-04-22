/*********************************************************************
 *
 * Title:            LoggerSetLoc.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/06/95 08:57
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/11/10 00:56:04  houghton
 * Initial Version
 *
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  LoggerSetLoc,
  "$Id$" );

extern BOOL  _CLogLoc;	/* _LoggerLogIt.c */

BOOL
LoggerSetLoc( BOOL newState )
{

  BOOL oldState = _CLogLoc;

  _CLogLoc = newState;

  return( oldState );
}


