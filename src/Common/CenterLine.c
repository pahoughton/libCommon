/*********************************************************************
*
*	Title:			CenterLine
*
*	Description:
*
*		center text line
*
*	Input Agrs:
*
*		char *dest		dest buffer
*		char *src		source buffer
*		int width		width to center for
*
*	Return Values:
*
*		char * dest;
*
*	Notes:
*
*	Programmer:		Paul Houghton
*
*	Start Date:		10-14-1991
*
*	Modification History:
*
*	$Log$
 * Revision 1.4  1994/08/15  19:56:59  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.3  1994/08/15  19:40:17  houghton
 * Cleanup; Rating QA1 Checkin
 *
 * Revision 1.2  1994/06/17  18:03:56  houghton
 * Cleanup for beta release.
 *
 * Revision 1.1  1994/01/31  14:06:12  houghton
 * Add avl and some other minor functions
 *
 * Revision 1.2  1992/01/01  21:22:44  paulh
 * Minor fixes
 *
 * Revision 1.1  1992/01/01  20:49:50  paulh
 * Initial revision
 *
*
*********************************************************************/
static const char * RcsId = 
{"$Id$"};

#include "_Common.h"

#include <string.h>
#include <stdlib.h>


char * CenterLine( char * dest, const char *src,int width)
{
  int	   pad;
  
  pad = width - strlen(src);
  pad /=2;
  
  memset(dest,' ',pad);
  dest[pad] = 0;
  strcat(dest,src);
  return( dest );
}

