/*********************************************************************
 *
 * File:        main.c
 * Project:	Common
 * Desc:
 *
 *  
 *
 * Notes:
 *
 * Author:	Paul A. Houghton - (paul.houghton@wcom.com)
 * Created:	09/16/98 10:09
 *
 * Revision History: (See end of file for Revision Log)
 *
 *  Last Mod By:    $Author$
 *  Last Mod:	    $Date$
 *  Version:	    $Revision$
 *
 *********************************************************************/

#include <Common.h>

#include "TestFunctProto.h"

#include <stdio.h>

struct TestFunct
{
  const char *	name;
  int		(*funct)( void );
};

struct TestFunct    Tests[] =
{
  {"strptime", tstrptime },
  {0, 0},
};

int
main( int argc, char * argv[] )
{
  
  if( argc > 1 )
    {
      int t;
      int tested;
      
      for( t = 1; t < argc; ++ t )
	{
	  int f;

	  tested = 0;
	  for( f = 0; Tests[ f ].name; ++ f )
	    {
	      if( strcmp( argv[ t ], Tests[ f ].name ) == 0 )
		{
		  tested = 1;
		  if( ! Tests[f].funct() )
		    {
		      printf( "%s failed!\n", Tests[f].name );
		      exit( 1 );
		    }
		  else
		    {
		      printf( "%s passed.\n", Tests[f].name );
		    }
		}
	    }
	  if( ! tested )
	    {
	      printf( "no test available for %s\n",
		      argv[t] );
	      exit( 1 );
	    }
	}
    }
  else
    {
      int f;
      for( f = 0; Tests[ f ].name; ++ f )
	{
	  if( ! Tests[f].funct() )
	    {
	      printf( "%s failed!\n", Tests[f].name );
	      exit( 1 );
	    }
	  else
	    {
	      printf( "%s passed.\n", Tests[f].name );
	    }
	}
    }
      
  return( 0 );
}

/*
 *
 * Revision Log:
 *
 * $Log$
 *
 */
