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
 * Revision 2.3  1998/07/20 11:04:10  houghton
 * Changed order of includes.
 *
 * Revision 2.2  1995/11/10 00:42:28  houghton
 * Modified to use new Error processing routines
 *
 * Revision 2.1  1995/10/28  19:11:36  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:10  houghton
 * Move to Version 2.0
 *
 * Revision 1.5  1994/07/13  14:53:59  houghton
 * Sequent port
 *
 * Revision 1.4  1994/06/20  15:28:37  dpotluri
 * LibCommon Port to OPENVMS
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

#include <stdio.h>
#include <stdlib.h>


COMMON_VERSION(
  ArgEnvInt,
  "$Id$");


Ret_Status
ArgEnvInt(
    int *         argc,
    char *  	  argv[],
    const char *  argId,
    const char *  envVar,
    int           minVal,
    int           maxVal,
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
	  
	  if( paramValue < minVal || paramValue > maxVal )
	    {
	      COMMON_RETURN_ERROR( EC_RANGE,
				   ("Max: %d Min: %d Value: %d",
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
	  paramValue = StringToInt( envStringVal, 0, 0 );
	  
	  if( paramValue < minVal || paramValue > maxVal )
	    {
	      COMMON_RETURN_ERROR( EC_RANGE,
				   ("Max: %d Min: %d Value: %d",
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