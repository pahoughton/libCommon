/* 1994-08-04 (cc) paul4hough@gmail.com

   Find an executable file in either the path parameter or
   the PATH environment varialbe (if path is NULL).
*/

#include "_Common.h"

#include <stdlib.h>
#include <string.h>

/* no gatesware :) */
#define PATH_SEP     ':'
#define PATH_SEP_STR ":"

char *
FindPath(
  const char * fileName,	/* name of file to look for (no wild cards) */
  const char * path		/* colon seperated path or NULL to use
				 * PATH environment variable */
  )
{

  char * envPath;
  char * pathDir;

  if( path == NULL )
    envPath = getenv( "PATH" );
  else
    envPath = (char *)path;

  if( strchr( fileName, PATH_SEP ) != NULL ||
      envPath == NULL )
    {
      if( CanExecute( fileName )  )
	return( strdup( (char *)fileName ) );
      else
	return( NULL );
    }

  envPath = strdup( envPath );	/* need private copy */

  for( pathDir = strtok( envPath, PATH_SEP_STR ) ;
       pathDir != NULL ;
       pathDir = strtok( NULL, PATH_SEP_STR ) )
    {
      char * fullName;

      if( (fullName = malloc( strlen( pathDir ) + strlen( fileName ) + 3 ) )
	  == NULL )
	{
	  free( envPath );
	  return( NULL );
	}

      strcpy( fullName, pathDir );
      strcat( fullName, "/" );
      strcat( fullName, fileName );

      if( CanExecute( fullName ) )
	{
	  free( envPath );
	  return( fullName );
	}
    }

  free( envPath );
  return( NULL );
}



/*
 *  sudo version 1.1 allows users to execute commands as root
 *  Copyright (C) 1991  The Root Group, Inc.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 1, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  If you make modifications to the source, we would be happy to have
 *  them to include in future releases.  Feel free to send them to:
 *      Jeff Nieusma                       nieusma@rootgroup.com
 *      3959 Arbol CT                      (303) 447-8093
 *      Boulder, CO 80301-1752
 *
 *******************************************************************
 *
 *  This module contains the find_path() command that returns
 *  a pointer to a static area with the absolute path of the
 *  command or NULL if the command is not found in the path
 *
 *  I also added the strdup() function in here after I found most
 *  systems don't have it...
 *
 *  Jeff Nieusma  Thu Mar 21 23:11:23 MST 1991
 */
