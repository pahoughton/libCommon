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
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";


#include <_Common.h>

const char *
basename( const char * name )
{
  const char * base;

  if( ( base = strrchr( name, '/' ) ) )
    {
      return( base );
    }
  else
    {
      return( name );
    }
}








/**
 * This software was swiped from the gnu code
 **/
