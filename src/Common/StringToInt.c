/*********************************************************************
 *
 * Title:            StringToInt.c
 *
 * Description:
 *
 *     	Convert a number string into its apropriate binary value.
 *  	If base is 0, the string will define its base as in C. A
 *  	leading 0 means octal and a leading 0x means hexidecimal.
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (houghton@cworld)
 *
 * Start Date:	    02/19/94 08:53
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.1  1994/06/06  13:23:36  houghton
 * Avl and DateTime functions added for Rating
 *
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";

#include "_Common.h"

int
StringToInt(
    const char * string,
    int		 baseToUse,
    int          len
    )
{
  return( (int)StringToLong( string, baseToUse, len ) );
}





