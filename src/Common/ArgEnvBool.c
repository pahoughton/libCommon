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
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include <_Common.h>
#include <Common.h>


int ArgEnvBool(
    int *   argc,
    char *  argv[],
    char *  argId,
    char *  envVar,
    int *   paramVar
    )
{
  
  int	paramValue;
  
  
  if( argId != NULL )
    {
      char *	argString = NULL;
      
      if( _ArgString( argc, argv, argId, &argString ) )
	{
	  return( ERROR );
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
		  SET_ERROR( E_RANGE );
		  return( ERROR );
		}
	    }
	  *paramVar = paramValue;
	  return( SUCCEED );
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
		  SET_ERROR( E_RANGE );
		  return( ERROR );
		}
	    }
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
