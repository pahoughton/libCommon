/*********************************************************************
 *
 * Title:            _ArgString.c
 *
 * Description:
 *
 *	Find the argv[] for the specified argId. For example, if
 *      the third argument to the program was -lf and the argId
 *  	was "lf", string would contain &(argv[4]), the next argument.
 *
 * Error Handling:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton (pah)
 *
 * Start Date:	    09/03/93 11:27
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.2  1995/11/10  01:03:19  houghton
 * Change to use new Error processing functions.
 *
 * Revision 2.1  1995/10/29  12:01:27  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:37  houghton
 * Move to Version 2.0
 *
 * Revision 1.3  1994/06/17  18:04:03  houghton
 * Cleanup for beta release.
 *
 *
 *********************************************************************/

#include "_Common.h"

#include <stdlib.h>
#include <stdio.h>


COMMON_VERSION(
  _ArgString,
  "$Id$");


int
_ArgString(
    int *   	  argc,
    char *  	  argv[],
    const char *  argId,
    char ** 	  string
    )
{
  int	    arg;

  if( *argc > 1 && argId != NULL )
    {
      if( argId[0] != 0 )
	{

	  for( arg = 1; arg < *argc; arg++ )
	    {
	      if( strcmp( argId, &(argv[arg][1]) ) == 0 )
		{
		  if( arg + 1 < *argc )
		    {
		      *string = argv[arg + 1];
		      
		      for( ; arg + 2 < *argc; arg++ )
			{
			  argv[arg] = argv[arg + 2];
			}
		      *argc -= 2;
		      break;
		    }
		  else
		    {
		      COMMON_SET_ERROR( EC_BADPARAM,("argument missing") );
		      return( RET_ERROR );
		    }
		}
	    }
	  
	  for( ; arg + 1  < *argc; arg++ )
	    {
	      argv[arg] = argv[arg + 1];
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
