/*********************************************************************
 *
 * Title:            strupr.c
 *
 * Description:
 *
 *	
 *
 * Error Handling:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton (pah)
 *
 * Start Date:	    01/29/94 21:02
 *
 * Modification History:
 *
 * $Log$
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";

#include <ctype.h>

char	*
strupr(
    char	*str
    )
{
  
  char	*string = str;
  
  
  while( *string != 0 )
    {
      if( islower(*string) )
	{
	  *string = toupper(*string);
	}
      string++;
    }
  return(str);
  
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

