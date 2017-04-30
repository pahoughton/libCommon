/* 1995-11-08 (cc) Paul Houghton <paul4hough@gmail.com>
 */

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
