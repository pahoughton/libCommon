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
 * Revision 2.3  1995/10/29 18:15:52  houghton
 * Fixes for Borland 4.0 Port
 *
 * Revision 2.2  1995/10/29  13:33:39  houghton
 * Initial Linux Build of Version 2
 *
 * Revision 2.1  1995/10/28  19:11:35  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:09  houghton
 * Move to Version 2.0
 *
 * Revision 1.3  1995/02/13  15:34:11  houghton
 * New functions and many enhancements to existing functions.
 *
 * Revision 1.2  1994/08/15  19:56:58  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.1  1994/08/15  19:42:18  houghton
 * Add ArgEnvFlage, ArgEnvLong, CanExecute, FindPath and MemberOfGroup
 * functions
 *
 *
 *********************************************************************/

#include "_Common.h"

#include <stdio.h>
#include <stdlib.h>

COMMON_VERSION(
  ArgEnvFlag,
  "$Id$");


Ret_Status
ArgEnvFlag(
    int *   	  argc,		/* argc from main */
    char *  	  argv[],	/* argv from main */
    const char *  argId,	/* arg identifier string */
    const char *  envVar,	/* env var identfier string */
    BOOL *     	  paramVar	/* assigned to value on return */
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
      if( getenv( envVar ) != NULL )
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
