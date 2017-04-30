/* 1994-08-02 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"

#include <stdio.h>
#include <stdlib.h>

COMMON_VERSION(
  ArgEnvFlag,
  "$Id$");


Ret_Status
ArgEnvFlag(
    int *   	  argc,		/* argc from main */
    char *  	  argv[],	/* argv from main */
    const char *  argId,	/* arg identifier string */
    const char *  envVar,	/* env var identfier string */
    BOOL *     	  paramVar	/* assigned to value on return */
    )
{

  if( argId != NULL )
    {
      if( *argc > 1 && argId[0] != 0 )
	{
	  int arg;

	  for( arg = 1; arg < *argc; arg++ )
	    {
	      if( strcmp( argId, &(argv[arg][1]) ) == 0 )
		{
		  *paramVar = TRUE;

		  for( ; arg + 1 < *argc; arg++ )
		    {
		      argv[arg] = argv[arg + 1];
		    }
		  *argc -= 1;
		  break;
		}
	    }
	}
    }

  if( envVar != NULL )
    {
      if( getenv( envVar ) != NULL )
	{
	  *paramVar = TRUE;
	}
    }
  return( RET_SUCCEED );
}
