/*********************************************************************
 *
 * Title            FindPath.c
 *
 * Description
 *
 *  	Find an executable file in either the path parameter or
 *	the PATH environment varialbe (if path is NULL).
 *	
 *
 * Notes
 *
 *   SEE end of file for original Copywrite and notices
 *   This module is covered by GPL
 *
 * Author:	    Jeff Nieusma
 *		    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date	    08/04/94 09:38
 *
 * Modification History
 *
 * $Log$
 * Revision 2.1  1995/10/28  19:11:45  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:22  houghton
 * Move to Version 2.0
 *
 * Revision 1.3  1995/02/13  15:34:17  houghton
 * New functions and many enhancements to existing functions.
 *
 * Revision 1.2  1994/08/15  19:57:01  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.1  1994/08/15  19:42:20  houghton
 * Add ArgEnvFlage, ArgEnvLong, CanExecute, FindPath and MemberOfGroup
 * functions
 *
 *
 *********************************************************************/

#include "_Common.h"

#include <string.h>
#include <stdlib.h>

COMMON_VERSION(
  FindPath,
  "$Id$");


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
    envPath = getenv( COMMON_PATH_ENV_VAR );
  else
    envPath = (char *)path;
  
  if( strchr( fileName, COMMON_DIR_SEP_CHAR ) != NULL ||
      envPath == NULL )
    {
      if( CanExecute( fileName )  )
	return( strdup( (char *)fileName ) );
      else
	return( NULL );
    }

  envPath = strdup( envPath );	/* need private copy */

  for( pathDir = strtok( envPath, COMMON_PATH_SEP ) ;
       pathDir != NULL ;
       pathDir = strtok( NULL, COMMON_PATH_SEP ) )
    {
      char * fullName;

      if( (fullName = malloc( strlen( pathDir ) + strlen( fileName ) + 3 ) )
	  == NULL )
	{
	  free( envPath );
	  return( NULL );
	}
      
      strcpy( fullName, pathDir );
      strcat( fullName, COMMON_DIR_SEP_STRING );
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
