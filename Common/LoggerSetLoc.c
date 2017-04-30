/* 1995-11-06 (cc) paul4hough@gmail.com
 */

#include "_Common.h"

extern BOOL  _CLogLoc;	/* _LoggerLogIt.c */

BOOL
LoggerSetLoc( BOOL newState )
{

  BOOL oldState = _CLogLoc;

  _CLogLoc = newState;

  return( oldState );
}
