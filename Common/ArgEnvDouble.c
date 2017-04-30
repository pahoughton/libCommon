/* 1994-08-19 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"

#include <stdio.h>
#include <stdlib.h>

COMMON_VERSION(
  ArgEnvDouble,
  "$Id$");


Ret_Status
ArgEnvDouble(
    int *         argc,
    char *  	  argv[],
    const char *  argId,
    const char *  envVar,
    double *      paramVar
    )
{

  double	paramValue;

  if( argId != NULL )
    {
      char *	argString = NULL;

      if( _ArgString( argc, argv, argId, &argString ) )
	{
	  return( RET_ERROR );
	}

      if( argString != NULL )
	{
	  paramValue = StringToDouble( argString, 0, 0 );

	  *paramVar = paramValue;
	  return( RET_SUCCEED );
	}
    }

  if( envVar != NULL )
    {
      char *	envStringVal;

      if( (envStringVal = getenv( envVar ) ) != NULL )
	{
	  paramValue = StringToDouble( envStringVal, 0, 0 );

	  *paramVar = paramValue;
	  return( RET_SUCCEED );
	}
    }

  return( RET_SUCCEED );
}
