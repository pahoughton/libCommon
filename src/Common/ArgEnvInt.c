/*********************************************************************
 *
 * Title:            ArgEnvInt.c
 *
 * Description:
 *
 *  Translate and environment variable and/or and command line argument
 *  into an integer
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
 * 6/7/94 - use StringToInt for conversion, allows using different bases.
 *
 * $Log$
 * Revision 1.2  1994/01/31  14:06:11  houghton
 * Add avl and some other minor functions
 *
 *
 *********************************************************************/
static const char * RcsID =
"$Id$";

#include <stdio.h>
#include <stdlib.h>

#include "_Common.h"


Ret_Status
ArgEnvInt(
    int *         argc,
    char *  	  argv[],
    const char *  argId,
    const char *  envVar,
    int           min,
    int           max,
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
	  
	  if( paramValue < min || paramValue > max )
	    {
	      SET_ERROR( C_ERANGE );
	      return( RET_ERROR );
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
	  
	  if( paramValue < min || paramValue > max )
	    {
	      SET_ERROR( C_ERANGE );
	      return( RET_ERROR );
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
