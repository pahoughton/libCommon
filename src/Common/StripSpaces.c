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
 * Revision 1.2  1994/06/17  18:04:02  houghton
 * Cleanup for beta release.
 *
 * Revision 1.1  1994/06/06  13:23:37  houghton
 * Avl and DateTime functions added for Rating
 *
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";

#include "_Common.h"

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
      
      


 
