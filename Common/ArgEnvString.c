/* 1993-09-03 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"

#include <stdio.h>
#include <stdlib.h>

COMMON_VERSION(
  ArgEnvString,
  "$Id$" );


Ret_Status
ArgEnvString(
    int *   	  argc,
    char *  	  argv[],
    const char *  argId,
    const char *  envVar,
    char ** 	  paramVar
    )
{

  char *    paramValue;

  if( paramVar == NULL )
    COMMON_RETURN_ERROR( EC_BADPARAM,
			 ("null pointer") );

  if( argId != NULL )
    {
      char *	argString = NULL;

      if( _ArgString( argc, argv, argId, &argString ) )
	{
	  return( RET_ERROR );
	}

      if( argString != NULL )
	{
	  if( (paramValue = malloc( strlen( argString ) + 1 )) == NULL )
	    {
	      SET_ERROR( ET_OSERROR, errno );
	      return( RET_ERROR );
	    }
	  strcpy( paramValue, argString );
	  *paramVar = paramValue;
	  return( RET_SUCCEED );
	}
    }

  if( envVar != NULL )
    {
      char *	envStringVal;

      if( (envStringVal = getenv( envVar ) ) != NULL )
	{
	  if( (paramValue = malloc( strlen( envStringVal ) + 1 )) == NULL )
	    {
	      SET_ERROR( ET_OSERROR, errno );
	      return( RET_ERROR );
	    }
	  strcpy( paramValue, envStringVal );
	  *paramVar = paramValue;
	  return( RET_SUCCEED );
	}
    }

  return( RET_SUCCEED );
}
