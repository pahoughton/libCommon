/*********************************************************************
 *
 * Title:            strdup.c
 *
 * Description:
 *
 *    	create a new string (on the heap) and copy input into it.
 *
 * Error Handling:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton (pah)
 *
 * Start Date:	    12/23/93 09:39
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.2  1995/12/02 02:12:37  houghton
 * *** empty log message ***
 *
 * Revision 2.1  1995/10/29  13:33:58  houghton
 * Initial Linux Build of Version 2
 *
 * Revision 2.0  1995/10/28  17:35:49  houghton
 * Move to Version 2.0
 *
 * Revision 1.2  1994/06/17  18:04:04  houghton
 * Cleanup for beta release.
 *
 *
 *********************************************************************/
#include "_Common.h"

#include <stdlib.h>
#include <string.h>

COMMON_VERSION(
  strdup,
  "$Id$");

char *
strdup( const char * input )
{
  char *    output;

  if( input == NULL ||
      (output = malloc( strlen( input ) + 1 ) ) == NULL )
    {
      return( NULL );
    }
  else
    {
      strcpy( output, input );
      return( output );
    }
}

	



