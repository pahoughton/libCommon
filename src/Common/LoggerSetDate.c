/*********************************************************************
 *
 * Title:            LoggerSetDate.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/07/95 13:19
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/11/10 00:56:03  houghton
 * Initial Version
 *
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  LoggerSetDate,
  "$Id$" );

extern BOOL _CLogDate;	/* _LoggerLogIt.c */

BOOL
LoggerSetDate( BOOL outputDate )
{
  BOOL old = _CLogDate;
  
  _CLogDate = outputDate;

  return( old );
}
