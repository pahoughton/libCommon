/*********************************************************************
 *
 * Title:            StripSpaces.c
 *
 * Description:
 *
 *	
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
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";

#include <Common.h>

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
      
      








/**
 *             This software is the sole property of
 *
 *                 The Williams Companies, Inc.
 *                       1 Williams Center
 *                         P.O. Box 2400
 *                      Tulsa, Oklahoma 74102
 *
 *        Copyright (c) 1993 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/
