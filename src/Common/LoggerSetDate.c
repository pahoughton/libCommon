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
