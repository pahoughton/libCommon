/*********************************************************************
 *
 * Title:            ArgEnvBool.c
 *
 * Description:
 *
 *  Translate and environment variable and/or and command line argument
 *  into an Bool (true/false)
 *
 * Error Handling:
 *
 *	Sets CommonErrno and returns 1
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton (pah)
 *
 * Start Date:	    09/03/93 10:10
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.4  1995/11/10  00:42:10  houghton
 * Modified to use new Error processing routines
 *
 * Revision 2.3  1995/10/29  13:33:39  houghton
 * Initial Linux Build of Version 2
 *
 * Revision 2.2  1995/10/28  19:11:33  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:08  houghton
 * Move to Version 2.0
 *
 * Revision 1.3  1994/06/17  18:03:55  houghton
 * Cleanup for beta release.
 *
 * Revision 1.2  1994/01/31  14:06:11  houghton
 * Add avl and some other minor functions
 *
 *
 *********************************************************************/

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


/**
 *             This software is the sole property of
 *
 *                 The Williams Companies, Inc.
 *                       1 Williams Center
 *                         P.O. Box 2400
 *                      Tulsa, Oklahoma 74102
 *
 *        Copyright (c) 1993 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/
