/*
// File:        IsLeapYear.c
// Desc:        
//
//  
//  
// Author:      Paul Houghton - (houghton@cworld1.wiltel.com)
// Created:     10/10/95 14:21
//
// Revision History:
//
// $Log$
*/

#include "_Common.h"
#include "DateTime.h"

COMMON_VERSION(
  IsLeapYear,
  "$Id$" );

BOOL
IsLeapYear( short year )
{
  return( !(year % 4) && ( (year % 100) || !(year % 400) ) );
}
  
