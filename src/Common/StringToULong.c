/*********************************************************************
 *
 * Title:            StringToULong.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    02/02/95 15:29
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.0  1995/10/28  17:35:32  houghton
 * Move to Version 2.0
 *
 * Revision 1.1  1995/02/13  15:34:21  houghton
 * New functions and many enhancements to existing functions.
 *
 *
 *********************************************************************/
#include "_Common.h"
#include <ctype.h>

COMMON_VERSION(
  StringToULong,
  "$Id$");



unsigned long
StringToULong(
    const char * string,
    int		 baseToUse,
    int          len
    )
{

  int index = 0;
  int base = 0;
  unsigned long value = 0;
  
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
 *        Copyright (c) 1994 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/
