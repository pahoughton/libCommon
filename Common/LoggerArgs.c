/* 1995-11-07 (cc) Paul Houghton <paul4hough@gmail.com>
 */

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
