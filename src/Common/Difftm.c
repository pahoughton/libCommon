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
 * Revision 1.2  1992/01/01  21:22:47  paulh
 * Minor fixes
 *
 * Revision 1.1  1992/01/01  20:49:53  paulh
 * Initial revision
 *
*
*********************************************************************/
static char RcsId[] = 
	{"$Id$"};

#include <time.h>

#include <Common.h>

time_t Difftm(struct tm *t1, struct tm *t2)

{

  return( mktime(t1) - mktime(t2) );

}
	

