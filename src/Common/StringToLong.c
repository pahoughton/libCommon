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
 * Revision 1.2  1994/06/20  10:27:20  houghton
 * Porting and add LoggerLoc function
 *
 * Revision 1.1  1994/06/17  18:07:30  houghton
 * Cool new Logger function
 *
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";


#include "_Common.h"
#include <ctype.h>

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

  for( ; (len != 0 && index < len ) || (len == 0 && string[index] != 0); index++ )
    {
      if( IsBaseDigit( string[index], base ) )
	{
	  value *= base;
	  value += CharToInt( string[index] );
	}
    }

  return( value );
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
