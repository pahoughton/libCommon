/* 1995-11-07 (cc) paul4hough@gmail.com
 */

#include "_Common.h"


extern BOOL _CLogDate;	/* _LoggerLogIt.c */

BOOL
LoggerSetDate( BOOL outputDate )
{
  BOOL old = _CLogDate;

  _CLogDate = outputDate;

  return( old );
}
