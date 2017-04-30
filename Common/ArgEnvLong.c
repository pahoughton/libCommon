/* 1994-08-15 (cc) paul4hough@gmail.com
 */

#include "Common.h"

#include <stdio.h>
#include <stdlib.h>


Ret_Status
ArgEnvLong(
    int *         argc,
    char *  	  argv[],
    const char *  argId,
    const char *  envVar,
    long           minVal,
    long           maxVal,
    long *         paramVar
    )
{

  long	paramValue;

  if( argId != NULL )
    {
      char *	argString = NULL;

      if( _ArgString( argc, argv, argId, &argString ) )
	{
	  return( RET_ERROR );
	}

      if( argString != NULL )
	{
	  paramValue = StringToLong( argString, 0, 0 );

	  if( paramValue < minVal || paramValue > maxVal )
	    {
	      COMMON_RETURN_ERROR( EC_RANGE,
				   ("Max: %ld Min: %ld Value: %ld",
				    maxVal, minVal, paramValue ) );
	    }
	  else
	    {
	      *paramVar = paramValue;
	      return( RET_SUCCEED );
	    }
	}
    }

  if( envVar != NULL )
    {
      char *	envStringVal;

      if( (envStringVal = getenv( envVar ) ) != NULL )
	{
	  paramValue = StringToLong( envStringVal, 0, 0 );

	  if( paramValue < minVal || paramValue > maxVal )
	    {
	      COMMON_RETURN_ERROR( EC_RANGE,
				   ("Max: %ld Min: %ld Value: %ld",
				    maxVal, minVal, paramValue ) );
	    }
	  else
	    {
	      *paramVar = paramValue;
	      return( RET_SUCCEED );
	    }
	}
    }

  return( RET_SUCCEED );
}
