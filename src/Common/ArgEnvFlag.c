/*********************************************************************
 *
 * Title:            ArgEnvFlag.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    08/02/94 09:06
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.2  1994/08/15  19:56:58  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.1  1994/08/15  19:42:18  houghton
 * Add ArgEnvFlage, ArgEnvLong, CanExecute, FindPath and MemberOfGroup
 * functions
 *
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";

#include <stdio.h>
#include <stdlib.h>

#include "_Common.h"


Ret_Status
ArgEnvFlag(
    int *   	  argc,		/* argc from main */
    char *  	  argv[],	/* argv from main */
    const char *  argId,	/* arg identifier string */
    const char *  envVar,	/* env var identfier string */
    Bool *     	  paramVar	/* assigned to value on return */
    )
{
    
  if( argId != NULL )
    {
      if( *argc > 1 && argId[0] != 0 )
	{
	  int arg;
	  
	  for( arg = 1; arg < *argc; arg++ )
	    {
	      if( strcmp( argId, &(argv[arg][1]) ) == 0 )
		{
		  *paramVar = TRUE;
		  
		  for( ; arg + 1 < *argc; arg++ )
		    {
		      argv[arg] = argv[arg + 1];
		    }
		  *argc -= 1;
		  break;
		}
	    }	    
	}
    }
  
  if( envVar != NULL )
    {
      char *	envStringVal;
      
      if( (envStringVal = getenv( envVar ) ) != NULL )
	{
	  *paramVar = TRUE;
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
