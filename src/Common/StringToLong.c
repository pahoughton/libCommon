/*********************************************************************
 *
 * Title:            StringToLong.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe)
 *
 * Start Date:	    06/16/94 08:19
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/10/29  12:01:22  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:31  houghton
 * Move to Version 2.0
 *
 * Revision 1.5  1995/02/13  15:34:20  houghton
 * New functions and many enhancements to existing functions.
 *
 * Revision 1.4  1994/08/15  19:57:09  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.3  1994/06/22  16:34:55  dpotluri
 * Port to MSWindows and OPENVMS
 *
 * Revision 1.2  1994/06/20  10:27:20  houghton
 * Porting and add LoggerLoc function
 *
 * Revision 1.1  1994/06/17  18:07:30  houghton
 * Cool new Logger function
 *
 *
 *********************************************************************/

#include "_Common.h"
#include <ctype.h>

COMMON_VERSION(
  StringToLong,
  "$Id$");


long
StringToLong(
    const char * string,
    int		 baseToUse,
    int          len
    )
{

  int index = 0;
  int base = 0;
  long value = 0;
  
  if( baseToUse == 0 )
    {
      for( index = 0;
	   ! isdigit( string[index] ) &&
	   ( (len != 0 && index < len ) ||
	     (len == 0 && string[index] != 0) )
	   ; index++ );

      if( string[index] == '0' )
	{
	  if( string[index + 1] == 'x' || string[index + 1] == 'X' )
	    {
	      base = 16;
	      index += 2;
	    }
	  else	
	    {
	      base = 8;
	      index += 1; 
	    }
	}
      else
	{
	  base = 10;
	}
    }
  else
    {
      base = baseToUse;
    }

  for( ; (len != 0 && index < len ) || (len == 0 && string[index] != 0);
       index++ )
    {
      if( IS_BASE_DIGIT( string[index], base ) )
	{
	  value *= base;
	  value += CHAR_TO_INT( string[index] );
	}
    }

  return( value );
}



