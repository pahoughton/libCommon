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
 * Revision 1.2  1994/06/17  18:04:04  houghton
 * Cleanup for beta release.
 *
 *
 *********************************************************************/
static const char * RcsID =
"$Id$";

#include <string.h>
#include <stdlib.h>

#include "_Common.h"
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

	



