/*********************************************************************
 *
 * Title:            ArgEnvLong.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    08/15/94 07:51
 *
 * Modification History:
 *
 * $Log$
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";



#include <stdio.h>
#include <stdlib.h>

#include "_Common.h"


Ret_Status
ArgEnvLong(
    int *         argc,
    char *  	  argv[],
    const char *  argId,
    const char *  envVar,
    long           minimumVal,
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
	  
	  if( paramValue < minimumVal || paramValue > maxVal )
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
	  paramValue = StringToLong( envStringVal, 0, 0 );
	  
	  if( paramValue < minimumVal || paramValue > maxVal )
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
