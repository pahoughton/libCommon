/*********************************************************************
 *
 * Title:			CenterLine
 *
 * Description:
 *
 *	center text line
 *
 * Input Agrs:
 *
 *	char *dest		dest buffer
 *	char *src		source buffer
 *	int width		width to center for
 *
 * Return Values:
 *
 *	char * dest;
 *
 * Notes:
 *
 * Programmer:		Paul Houghton
 *
 * Start Date:		10-14-1991
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.2  1995/11/10  12:07:54  houghton
 * AIX Port
 * Cleanup and reorder includes
 *
 * Revision 2.1  1995/10/28  19:11:38  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:15  houghton
 * Move to Version 2.0
 *
 * Revision 1.5  1995/02/13  15:34:13  houghton
 * New functions and many enhancements to existing functions.
 *
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

#include "_Common.h"

#include <string.h>

COMMON_VERSION(
  CenterLine,
  "$Id$" );

char * CenterLine( char * dest, const char * src,int width)
{
  size_t    pad;
  size_t    srcLen = strlen( src );

  if( width < 0 || ((size_t)width) > srcLen )
    {
      pad = 0;
    }
  else
    {
      pad = ((size_t)width) - srcLen;
      pad /=2;
    }
  
  memset(dest,' ',pad);
  dest[pad] = 0;
  strcat(dest,src);
  return( dest );
}

