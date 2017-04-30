/* 1994-07-06 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"
#include <stdio.h>

COMMON_VERSION(
  Logger,
  "$Id$" );


LogLevelBit	_CLogCurMesgLevel;
const char *	_CLogLocFile;
long		_CLogLocLine;

void
Logger( const char * mesgFmt, ... )
{

  va_list   args;

  va_start( args, mesgFmt );

  LoggerArgs( _CLogLocFile,
	      _CLogLocLine,
	      _CLogCurMesgLevel,
	      NULL,
	      mesgFmt,
	      args );

  va_end( args );
}
