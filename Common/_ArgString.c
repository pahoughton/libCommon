/* 1994-08-04 (cc) Paul Houghton <paul4hough@gmail.com>

   Find the argv[] for the specified argId. For example, if
   the third argument to the program was -lf and the argId
   was "lf", string would contain &(argv[4]), the next argument.

*/
#include "_Common.h"

#include <stdlib.h>
#include <stdio.h>


COMMON_VERSION(
  _ArgString,
  "$Id$");


int
_ArgString(
    int *   	  argc,
    char *  	  argv[],
    const char *  argId,
    char ** 	  string
    )
{
  int	    arg;

  if( *argc > 1 && argId != NULL )
    {
      if( argId[0] != 0 )
	{

	  for( arg = 1; arg < *argc; arg++ )
	    {
	      if( strcmp( argId, &(argv[arg][1]) ) == 0 )
		{
		  if( arg + 1 < *argc )
		    {
		      *string = argv[arg + 1];

		      for( ; arg + 2 < *argc; arg++ )
			{
			  argv[arg] = argv[arg + 2];
			}
		      *argc -= 2;
		      break;
		    }
		  else
		    {
		      COMMON_SET_ERROR( EC_BADPARAM,("argument missing") );
		      return( RET_ERROR );
		    }
		}
	    }

	  for( ; arg + 1  < *argc; arg++ )
	    {
	      argv[arg] = argv[arg + 1];
	    }
	}
    }

  return( RET_SUCCEED );

}
