/*********************************************************************
 *
 * File:        tHourMinSecToTimeT.c
 * Project:	Common
 * Desc:
 *
 *  
 *
 * Notes:
 *
 * Author:	Paul A. Houghton - (paul.houghton@wcom.com)
 * Created:	09/24/98 07:04
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


int
tHourMinSecToTimeT( void )
{

 int	    ret = 1;
  
  time_t    hour;
  time_t    min;
  time_t    sec;
  time_t    value;
  time_t    expect;
  
  for( hour = 0; hour < 23; ++ hour )
    {
      for( min = 0; min < 59; ++ min )
	{
	  for( sec = 0; sec < 59; ++ sec )
	    {
	      value = HourMinSecToTimeT( hour, min, sec );

	      expect = ( sec
			 + ( min * 60 )
			 + ( hour * 60 * 60 ) );
	      
	      if( value != expect )
		{
		  printf( "HourMinSecToTimeT: FAILED - exp: %ld  is: %ld\n",
			  expect,
			  value );
		  ret = 0;
		}
	    }
	}
    }
  return( ret );
}

/*
 *
 * Revision Log:
 *
 * $Log$
 *
 */
