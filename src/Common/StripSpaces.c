/*********************************************************************
 *
 * Title:            StripSpaces.c
 *
 * Description:
 *
 *	Remove leading and trailing spaces from a string.
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe)
 *
 * Start Date:	    02/18/94 16:33
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/10/29 12:01:25  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:34  houghton
 * Move to Version 2.0
 *
 * Revision 1.3  1994/08/15  19:57:09  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.2  1994/06/17  18:04:02  houghton
 * Cleanup for beta release.
 *
 * Revision 1.1  1994/06/06  13:23:37  houghton
 * Avl and DateTime functions added for Rating
 *
 *
 *********************************************************************/
#include "_Common.h"

COMMON_VERSION(
  StripSpaces,
  "$Id$");


void
StripSpaces( char * buffer )
{

  int	cnt;
  int   pos = 0;
  
  for( cnt = 0; buffer[cnt] != 0 && buffer[cnt] == ' '; cnt++ );

  if( cnt != 0 )
    {
      for( pos = 0; buffer[cnt] != 0; pos++, cnt++ )
	{
	  buffer[pos] = buffer[cnt];
	}
      buffer[pos] = 0;
    }
  else
    {
      pos = strlen( buffer );
    }
  pos--;  
  cnt = pos;
  for( ; pos != 0 && buffer[pos] == ' ' ; pos-- );

  pos++;
  buffer[pos] = 0;
}
      
      


 
