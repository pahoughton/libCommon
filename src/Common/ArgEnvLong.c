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
 * Revision 2.2  1995/11/10 00:42:39  houghton
 * Modified to use new Error processing routines
 *
 * Revision 2.1  1995/10/28  19:11:36  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:11  houghton
 * Move to Version 2.0
 *
 * Revision 1.2  1994/08/15  19:56:59  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.1  1994/08/15  19:42:19  houghton
 * Add ArgEnvFlage, ArgEnvLong, CanExecute, FindPath and MemberOfGroup
 * functions
 *
 *
 *********************************************************************/

#include "_Common.h"

#include <stdio.h>
#include <stdlib.h>

COMMON_VERSION(
  ArgEnvLong,
  "$Id$");


Ret_Status
ArgEnvLong(
    int *         argc,
    char *  	  argv[],
    const char *  argId,
    const char *  envVar,
    long           minVal,
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
	  
	  if( paramValue < minVal || paramValue > maxVal )
	    {
	      COMMON_RETURN_ERROR( EC_RANGE,
				   ("Max: %ld Min: %ld Value: %ld",
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
	  paramValue = StringToLong( envStringVal, 0, 0 );
	  
	  if( paramValue < minVal || paramValue > maxVal )
	    {
	      COMMON_RETURN_ERROR( EC_RANGE,
				   ("Max: %ld Min: %ld Value: %ld",
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
