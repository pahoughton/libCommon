/*********************************************************************
 *
 * Title:            StringToUShort.c
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
 * Revision 2.3  1998/09/22 14:33:24  houghton
 * Port(Linux): I was using 'index' as a variable name. This is also a
 *     syninoum for strchr(), so I change the variable name to avoid
 *     warnings.
 *
 * Revision 2.2  1995/10/29 13:33:47  houghton
 * Initial Linux Build of Version 2
 *
 * Revision 2.1  1995/10/29  12:01:25  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:33  houghton
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
  StringToUShort,
  "$Id$");


unsigned short
StringToUShort(
    const char * string,
    int		 baseToUse,
    int          len
    )
{

  int pos = 0;
  int base = 0;
  unsigned short value = 0;
  
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

  for( ; (len != 0 && pos < len ) || (len == 0 && string[pos] != 0);
       pos++ )
    {
      if( IS_BASE_DIGIT( string[pos], base ) )
	{
	  value *= base;
	  value += CHAR_TO_INT( string[pos] );
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
