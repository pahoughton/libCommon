/*********************************************************************
 *
 * Title:            LoggerArgs.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/07/95 11:21
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/11/10 00:56:02  houghton
 * Initial Version
 *
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  LoggerArgs,
  "$Id$" );

LoggerFunct  _CLoggerFunct  = _LoggerDefault;
void *	    _CLoggerClosure = NULL;

BOOL	_CLogTee;

void
LoggerArgs(
  const char *  srcFileName,
  long		srcLineNumber,
  LogLevelBit   level,
  void *	closure,
  const char *  mesgFmt,
  va_list	mesgArgs
  )
{
  
  if( _CLogTee == TRUE )
    {
      _LoggerLogIt( stderr,
		    srcFileName,
		    srcLineNumber,
		    level,
		    mesgFmt,
		    mesgArgs );
    }
  
  if( _CLoggerFunct != NULL )
    {
      _CLoggerFunct( ( ( closure != 0 ) ?
		       closure : _CLoggerClosure ),
		     srcFileName,
		     srcLineNumber,
		     level,
		     mesgFmt,
		     mesgArgs );
      
    }
}
