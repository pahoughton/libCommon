/*********************************************************************
 *
 * Title:            basename.c
 *
 * Description:
 *
 *  gve the file name from a path nam
 *
 *  for /usr/local/include/std.h basename returns std.h
 *  for include/std.h basename returns std.h
 *  for std.h basename returns std.h
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    01/28/95 18:14
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/10/29  13:33:57  houghton
 * Initial Linux Build of Version 2
 *
 * Revision 2.0  1995/10/28  17:35:48  houghton
 * Move to Version 2.0
 *
 * Revision 1.2  1995/07/31  17:56:28  dpotluri
 * Igor's fix to basename
 *
 * Revision 1.1  1995/02/13  15:34:24  houghton
 * New functions and many enhancements to existing functions.
 *
 *
 *********************************************************************/
#include "_Common.h"

COMMON_VERSION(
  basename,
  "$Id$");


const char *
basename( const char * name )
{
  const char * base;

  if( ( base = strrchr( name, COMMON_DIR_SEP_CHAR ) ) != 0)
    return( base + 1 );
  else
    return( name );
}








/**
 * This software was swiped from the gnu code
 **/
