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
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include <_Common.h>
#include <Common.h>


int ArgEnvString(
    int *   argc,
    char *  argv[],
    char *  argId,
    char *  envVar,
    char ** paramVar
    )
{

  char *    paramValue;

  if( paramVar == NULL )
    {
      return( E_BADPARAM );
    }
  
  if( argId != NULL )
    {
      char *	argString = NULL;
      
      if( _ArgString( argc, argv, argId, &argString ) )
	{
	  return( ERROR );
	}
      
      if( argString != NULL )
	{
	  if( (paramValue = malloc( strlen( argString ) + 1 )) == NULL )
	    {
	      SET_ERROR( E_OSERROR );
	      return( ERROR );
	    }
	  strcpy( paramValue, argString );
	  *paramVar = paramValue;
	  return( SUCCEED );
	}
    }
  
  if( envVar != NULL )
    {
      char *	envStringVal;
      
      if( (envStringVal = getenv( envVar ) ) != NULL )
	{
	  if( (paramValue = malloc( strlen( envStringVal ) + 1 )) == NULL )
	    {
	      SET_ERROR( E_OSERROR );
	      return( ERROR );
	    }
	  strcpy( paramValue, envStringVal );
	  *paramVar = paramValue;
	  return( SUCCEED );
	}
    }
  
  return( SUCCEED );
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
