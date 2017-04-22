/*********************************************************************
 *
 * File:        tIsLeapYear.c
 * Project:	Common
 * Desc:
 *
 *  
 *
 * Notes:
 *
 * Author:	Paul A. Houghton - (paul.houghton@wcom.com)
 * Created:	09/23/98 06:45
 *
 * Revision History: (See end of file for Revision Log)
 *
 *  Last Mod By:    $Author$
 *  Last Mod:	    $Date$
 *  Version:	    $Revision$
 *
 *********************************************************************/

#include "TestConfig.h"
#include "TestFunctProto.h"
#include "Common.h"

#include <time.h>
#include <stdio.h>

struct TestValues
{
  short	year;
  short isLeap;
};

static struct TestValues TestData[] =
{
  { 1600, TRUE },
  { 1700, FALSE },
  { 1800, FALSE },
  { 1900, FALSE },
  { 2000, TRUE },
  
  { 1960, TRUE },
  { 1961, FALSE },
  { 1962, FALSE },
  { 1993, FALSE },
  { 1964, TRUE },

  { 1990, FALSE },
  { 1991, FALSE },
  { 1992, TRUE },
  { 1993, FALSE },
  { 1994, FALSE },
  { 1995, FALSE },
  { 1996, TRUE },
  { 1997, FALSE },
  { 1998, FALSE },
  { 1999, FALSE },
  { 2000, TRUE },
  { 2001, FALSE },
  { 2002, FALSE },
  { 2003, FALSE },
  { 2004, TRUE },
  { 0, FALSE }
};

int
tIsLeapYear( void )
{
  int status = 1;
  int l;
  
  for( l = 0; TestData[ l ].year; ++ l )
    {
      if( ( IsLeapYear( TestData[ l ].year ) ? 1 : 0 )
	  != ( TestData[ l ].isLeap ? 1 : 0 ) )
	{
	  printf( "IsLeapYear: FAILED - %d %c\n",
		  TestData[ l ].year,
		  (IsLeapYear( TestData[ l ].year ) ? 'Y' : 'N' ) );
	  status = 0;
	}
    }
  return( status );
}

/*
 *
 * Revision Log:
 *
 * $Log$
 * Revision 1.1  1998/09/24 15:28:29  houghton
 * Initial Version.
 *
 *
 */
