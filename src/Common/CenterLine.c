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
*		NONE
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
 * Revision 1.2  1992/01/01  21:22:44  paulh
 * Minor fixes
 *
 * Revision 1.1  1992/01/01  20:49:50  paulh
 * Initial revision
 *
*
*********************************************************************/
static char RcsId[] = 
{"$Id$"};


#include <string.h>
#include <stdlib.h>

#include <Common.h>


void CenterLine( char *dest, const char *src,int width)
{
  int	   pad;
  
  pad = width - strlen(src);
  pad /=2;
  
  memset(dest,' ',pad);
  dest[pad] = 0;
  strcat(dest,src);
  return;
}

