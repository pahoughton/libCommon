/*********************************************************************
 *
 * Title:            ArgEnvString.c
 *
 * Description:
 *
 *  Translate and environment variable and/or and command line argument
 *  into a String value
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
 * Revision 2.3  1998/07/20 11:04:16  houghton
 * Changed order of includes.
 *
 * Revision 2.2  1995/11/10 00:43:58  houghton
 * Modified to use new Error processing routines
 *
 * Revision 2.1  1995/10/28  19:11:37  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:11  houghton
 * Move to Version 2.0
 *
 * Revision 1.3  1994/06/17  18:03:56  houghton
 * Cleanup for beta release.
 *
 * Revision 1.2  1994/01/31  14:06:12  houghton
 * Add avl and some other minor functions
 *
 * 
 *********************************************************************/

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
