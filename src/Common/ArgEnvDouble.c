/*********************************************************************
 *
 * Title:            ArgEnvDouble.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    08/19/94 07:42
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.0  1995/10/28  17:35:09  houghton
 * Move to Version 2.0
 *
 * Revision 1.1  1995/02/13  15:34:09  houghton
 * New functions and many enhancements to existing functions.
 *
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "_Common.h"

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

/**
 *             This software is the sole property of
 *
 *                 The Williams Companies, Inc.
 *                       1 Williams Center
 *                         P.O. Box 2400
 *                      Tulsa, Oklahoma 74102
 *
 *        Copyright (c) 1994 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/
