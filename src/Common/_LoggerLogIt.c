/*********************************************************************
 *
 * Title:            _LoggerLogIt.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/07/95 07:20
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/11/10  00:56:08  houghton
 * Initial Version
 *
 *
 *********************************************************************/

#include "_Common.h"
#include <stdio.h>
#include <stdarg.h>

COMMON_VERSION(
  _LoggerLogIt,
  "$Id$" );

BOOL		_CLogDate = TRUE;
BOOL		_CLogLoc  = TRUE;

void
_LoggerLogIt(
  FILE *	log,
  const char *  srcFileName,
  long		srcLineNumber,
  LogLevelBit   level,
  const char *  mesgFmt,
  va_list	mesgArgs
  )
{
  if( _CLogDate == TRUE )
    {
      time_t  nowSec = time(0);
      struct tm * now = localtime( &nowSec );
      
      fprintf( log,"%02d/%02d/%02d %02d:%02d:%02d ",
	       now->tm_mon + 1,
	       now->tm_mday,
	       now->tm_year,
	       now->tm_hour,
	       now->tm_min,
	       now->tm_sec );
      
    }
  
  fprintf( log, "%s: ", LogLevelString( level ) );
  
  if( _CLogLoc == TRUE && srcFileName != NULL )
    {
      fprintf( log,"%s:%ld: ", srcFileName, srcLineNumber );
    }
  
  vfprintf( log, mesgFmt, mesgArgs );
  
}  

  
