/*********************************************************************
*
*	Title:			Difftm
*
*	Description:
*
*		compares tm structs, returns the diff in seconds
*
*	Input Agrs:
*
*
*	Return Values:
*
*		diff in sec between t1 & t2
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
 * Revision 1.4  1994/08/15  19:57:01  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.3  1994/07/05  21:39:14  houghton
 * Minor fixes and cleanup header info.
 *
 * Revision 1.2  1994/06/17  18:03:58  houghton
 * Cleanup for beta release.
 *
 * Revision 1.1  1994/01/31  14:06:13  houghton
 * Add avl and some other minor functions
 *
 * Revision 1.2  1992/01/01  21:22:47  paulh
 * Minor fixes
 *
 * Revision 1.1  1992/01/01  20:49:53  paulh
 * Initial revision
 *
*
*********************************************************************/
static const char * RcsId = 
"$Id$";

#include <time.h>

#include "_Common.h"

time_t Difftm(struct tm *t1, struct tm *t2)

{

  return( mktime(t1) - mktime(t2) );

}
	

/*
 * Public Domain - no copyright
 */
