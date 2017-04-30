/* 1993-09-03 (cc) Paul Houghton <paul4hough@gmail.com>
 */

#include "_Common.h"

#include <stdlib.h>
#include <stdio.h>

COMMON_VERSION(
  ArgEnvBool,
  "$Id$");


Ret_Status
ArgEnvBool(
    int *   	  argc,		/* argc from main */
    char *  	  argv[],	/* argv from main */
    const char *  argId,	/* arg identifier string */
    const char *  envVar,	/* env var identfier string */
    int *   	  paramVar	/* assigned to value on return */
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
	  strlwr( argString );

	  if( strcmp( argString, "true" ) == 0 ||
	      strcmp( argString, "on" ) == 0 ||
	      strcmp( argString, "yes" ) == 0 )
	    {
	      paramValue = 1;
	    }
	  else
	    {
	      if( strcmp( argString, "false" ) == 0 ||
		  strcmp( argString, "off" ) == 0 ||
		  strcmp( argString, "no" ) == 0 )
		{
		  paramValue = 0;
		}
	      else
		{
		  COMMON_RETURN_ERROR( EC_RANGE,
				       ( "'%s' is not a valid Bool value",
					 argString ) );
		}
	    }
	  *paramVar = paramValue;
	  return( RET_SUCCEED );
	}
    }

  if( envVar != NULL )
    {
      char *	envStringVal;

      if( (envStringVal = getenv( envVar ) ) != NULL )
	{
	  strlwr( envStringVal );

	  if( strcmp( envStringVal, "true" ) == 0 ||
	      strcmp( envStringVal, "on" ) == 0 ||
	      strcmp( envStringVal, "yes" ) == 0 )
	    {
	      paramValue = 1;
	    }
	  else
	    {
	      if( strcmp( envStringVal, "false" ) == 0 ||
		  strcmp( envStringVal, "off" ) == 0 ||
		  strcmp( envStringVal, "no" ) == 0 )
		{
		  paramValue = 0;
		}
	      else
		{
		  COMMON_RETURN_ERROR( EC_RANGE,
				       ("'%s' is not a valid Bool value",
				       envStringVal ) );
		}
	    }
	  *paramVar = paramValue;
	  return( RET_SUCCEED );
	}
    }

  return( RET_SUCCEED );
}
