/*********************************************************************
 *
 * Title:            StringToDouble.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    08/19/94 07:46
 *
 * Modification History:
 *
 * $Log$
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";


#include "_Common.h"
#include <ctype.h>
#include <math.h>

double
StringToDouble(
    const char * string,
    int		 baseToUse,
    int          len
    )
{

  int index = 0;
  int base = 0;
  int	fract = -1;
  double value = 0;
  
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
	  if( fract > -1 )
	    {
	      fract++;
	    }
	  value *= base;
	  value += CharToInt( string[index] );
	}
      else
	{
	  if( string[index] == '.' )
	    {
	      fract = 0;
	    }
	}
    }

  if( fract > 0 )
    {
      value = value * pow( 10, -1 * fract );
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
 *        Copyright (c) 1994 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/
