/*
 * File:        IsLeapYear.c
 * Desc:        
 *
 *  
 *  
 * Author:      Paul Houghton - (houghton@cworld1.wiltel.com)
 * Created:     10/10/95 14:21
 *
 * Revision History:
 *
 * $Log$
 * Revision 2.1  1995/10/28  19:18:18  houghton
 * New for version 2.0
 *
 */

#include "_Common.h"

COMMON_VERSION(
  IsLeapYear,
  "$Id$" );

BOOL
IsLeapYear( short year )
{
  return( !(year % 4) && ( (year % 100) || !(year % 400) ) );
}
  
