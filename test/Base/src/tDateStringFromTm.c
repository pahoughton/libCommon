/*********************************************************************
 *
 * File:        tDateStringFromTm.c
 * Project:	Common
 * Desc:
 *
 *  
 *
 * Notes:
 *
 * Author:	Paul A. Houghton - (paul.houghton@wcom.com)
 * Created:	09/24/98 06:30
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

static
int
test(
  const char *	exp,
  const char *	fmt,
  int		year,
  int		mon,
  int		day,
  int		hour,
  int		min,
  int		sec
  )
{
  int		ret = 1;
  char		value[ 128 ];
  const char *	ptr;
  struct tm	tm;

  memset( &tm, 0, sizeof( tm ) );

  tm.tm_year	= year - 1900;
  tm.tm_mon	= mon - 1;
  tm.tm_mday	= day;
  tm.tm_hour	= hour;
  tm.tm_min	= min;
  tm.tm_sec	= sec;

  ptr = DateStringFromTm( 0, fmt, &tm );

  if( strcmp( ptr, exp ) )
    {
      printf( "DateStringFromTm: FAILED\n"
	      "  got:  %s\n"
	      "  exp:  %s\n",
	      ptr,
	      exp );
      ret = 0;
    }

  ptr = DateStringFromTm( value, fmt, &tm );

  if( ptr != value || strcmp( ptr, exp ) )
    {
      printf( "DateStringFromTm: FAILED\n"
	      "  got:  %s\n"
	      "  exp:  %s\n",
	      ptr,
	      exp );
      ret = 0;
    }

  return( ret );
}


int
tDateStringFromTm( void )
{

  int ret = 1;

  ret &= test( "01/01/1940 05:23:49",
	       0,
	       1940,
	       1,
	       1,
	       5,
	       23,
	       49 );

  ret &= test( "01/01/1960 23:59:00",
	       0,
	       1960,
	       1,
	       1,
	       23,
	       59,
	       0 );

  ret &= test( "01/01/1970 00:00:00",
	       0,
	       1970,
	       1,
	       1,
	       0,
	       0,
	       0 );

  ret &= test( "01/01/1999 12:00:04",
	       0,
	       1999,
	       1,
	       1,
	       12,
	       0,
	       4 );

  ret &= test( "12/31/1999 23:59:59",
	       0,
	       1999,
	       12,
	       31,
	       23,
	       59,
	       59 );

  ret &= test( "01/01/2000 00:00:00",
	       0,
	       2000,
	       1,
	       1,
	       0,
	       0,
	       0 );

  ret &= test( "10/01/2001 00:00:00",
	       0,
	       2001,
	       10,
	       1,
	       0,
	       0,
	       0 );

  ret &= test( "02/28/2025 00:01:01",
	       0,
	       2025,
	       2,
	       28,
	       0,
	       1,
	       1 );

  ret &= test( "01/01/1950",
	       "%m/%d/%Y",
	       1950,
	       1,
	       1,
	       10,
	       50,
	       52 );
  
  ret &= test( "01/01/1960 14:50",
	       "%m/%d/%Y %H:%M",
	       1960,
	       1,
	       1,
	       14,
	       50,
	       23 );
  
  ret &= test( "01/01/1970",
	       "%m/%d/%Y",
	       1970,
	       1,
	       1,
	       12,
	       12,
	       12 );
  
  ret &= test( "01/01/1980 23:59:59",
	       "%m/%d/%Y %H:%M:%S",
	       1980,
	       1,
	       1,
	       23,
	       59,
	       59 );
  
  ret &= test( "12/31/1999 22:00",
	       "%m/%d/%Y %H:%M",
	       1999,
	       12,
	       31,
	       22,
	       0,
	       53 );
  
  ret &= test( "01/01/2000 10:00:04",
	       "%m/%d/%Y %H:%M:%S",
	       2000,
	       1,
	       1,
	       10,
	       0,
	       4 );
  
  return( ret );
	       
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
