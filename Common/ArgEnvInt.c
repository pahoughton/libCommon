/* 1993-09-03 (cc) Paul Houghton <paul4hough@gmail.com>

   Translate and environment variable and/or and command line argument
   into an integer
*/

#include "_Common.h"

#include <stdio.h>
#include <stdlib.h>


Ret_Status
ArgEnvInt(
    int *         argc,
    char *  	  argv[],
    const char *  argId,
    const char *  envVar,
    int           minVal,
    int           maxVal,
    int *         paramVar
    )
{

  int	paramValue;

  if( argId != NULL )
    {
      char *	argString = NULL;

      if( _ArgString( argc, argv, argId, &argString ) )
	{
	  return( RET_ERROR );
	}

      if( argString != NULL )
	{
	  paramValue = StringToInt( argString, 0, 0 );

	  if( paramValue < minVal || paramValue > maxVal )
	    {
	      COMMON_RETURN_ERROR( EC_RANGE,
				   ("Max: %d Min: %d Value: %d",
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
	  paramValue = StringToInt( envStringVal, 0, 0 );

	  if( paramValue < minVal || paramValue > maxVal )
	    {
	      COMMON_RETURN_ERROR( EC_RANGE,
				   ("Max: %d Min: %d Value: %d",
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
