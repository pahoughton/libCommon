/*********************************************************************
 *
 * Title:            LoggerSetTee.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/08/95 17:11
 *
 * Modification History:
 *
 * $Log$
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  LoggerSetTee,
  "$Id$" );

extern BOOL _CLogTee;	/* LoggerArgs.c */

BOOL
LoggerSetTee( BOOL  teeOutput )
{
  BOOL old = _CLogTee;
  _CLogTee = teeOutput;
  return( old );
}


