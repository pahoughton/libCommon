/*********************************************************************
 *
 * Title:            _ArgString.c
 *
 * Description:
 *
 *	
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
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include <_Common.h>
#include <Common.h>

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
		      SET_ERROR( C_EBADPARAM );
		      return( RET_ERROR );
		    }
		}
	    }
	}
      
      for( ; arg + 1  < *argc; arg++ )
	{
	  argv[arg] = argv[arg + 1];
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
