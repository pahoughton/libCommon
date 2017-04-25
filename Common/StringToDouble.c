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
 * Revision 2.4  1998/09/22 14:33:05  houghton
 * Port(Linux): I was using 'index' as a variable name. This is also a
 *     syninoum for strchr(), so I change the variable name to avoid
 *     warnings.
 *
 * Revision 2.3  1995/12/02 02:07:49  houghton
 * Fix to eliminate compiler warnings.
 *
 * Revision 2.2  1995/10/29  13:33:44  houghton
 * Initial Linux Build of Version 2
 *
 * Revision 2.1  1995/10/29  12:01:21  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:30  houghton
 * Move to Version 2.0
 *
 * Revision 1.1  1995/02/13  15:34:19  houghton
 * New functions and many enhancements to existing functions.
 *
 *
 *********************************************************************/

#include "_Common.h"

#include <ctype.h>
#include <math.h>

COMMON_VERSION(
  StringToDouble,
  "$Id$");


double
StringToDouble(
    const char * string,
    int		 baseToUse,
    int          len
    )
{

  int pos = 0;
  int base = 0;
  int	fract = -1;
  double value = 0;
  
  if( baseToUse == 0 )
    {
      for( pos = 0;
	   ! isdigit( string[pos] ) &&
	   ( (len != 0 && pos < len ) ||
	     (len == 0 && string[pos] != 0) )
	   ; pos++ );

      if( string[pos] == '0' )
	{
	  if( string[pos + 1] == 'x' || string[pos + 1] == 'X' )
	    {
	      base = 16;
	      pos += 2;
	    }
	  else	
	    {
	      base = 8;
	      pos += 1; 
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

  for( ; (len != 0 && pos < len ) || (len == 0 && string[pos] != 0); pos++ )
    {
      
      if( IS_BASE_DIGIT( string[pos], base ) )
	{
	  if( fract > -1 )
	    {
	      fract++;
	    }
	  value *= base;
	  value += CHAR_TO_INT( string[pos] );
	}
      else
	{
	  if( string[pos] == '.' )
	    {
	      fract = 0;
	    }
	}
    }

  if( fract > 0 )
    {
      value = value * pow( (double)10, (double)(-1 * fract) );
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
