/*********************************************************************
 *
 * Title:            ForeachFile.c
 *
 * Description:
 *
 *	Execute a function (fileProc) for each file in a dirctory
 *   	tree. If recurs is true, walk down sub dirs.
 *
 * Error Handling:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Information Industies, Inc. - Paul Houghton (pah)
 *
 * Start Date:	    07/23/93 14:10
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.4  1994/06/20  15:28:40  dpotluri
 * LibCommon Port to OPENVMS
 *
 * Revision 1.3  1994/06/17  18:03:59  houghton
 * Cleanup for beta release.
 *
 * Revision 1.2  1994/02/02  14:38:26  houghton
 * Had to rename error to LibError because of a conflicts with other
 * symbols. Minor mods to other files
 *
 * Revision 1.1  1994/01/31  14:06:14  houghton
 * Add avl and some other minor functions
 *
 *
 *********************************************************************/
static const char RcsId[] =
{"$Id$"};


#define _ALL_SOURCE
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#include "_Common.h"

Ret_Status
ForeachFile(
    const char *    dirName,
    Ret_Status      (*fileProc)( const char * name, void * closure ),
    Bool    	    recurs,
    void *  	    closure 
    )
{
  

  struct stat	fileStat;
  
  
  if( stat( dirName, &fileStat ) != 0 )
    {
      SET_ERROR( C_EOSERROR );
      return( RET_ERROR );
    }
  
  if( S_ISDIR( fileStat.st_mode ) == TRUE )
    {
      
      DIR	    	*dir;
      struct dirent	*dirInfo;
      
      if( (dir = opendir( dirName ) ) == NULL )
	{
	  SET_ERROR( C_EOSERROR );
	  return( RET_ERROR );
	}
      
      while( (dirInfo = readdir( dir )) != NULL )
	{
	  char * pathName;
	  if( strcmp( dirInfo->d_name, ".") == 0 ||
	      strcmp( dirInfo->d_name, ".." ) == 0 )
	    {
	      continue;
	    }
	  pathName = malloc( strlen( dirName ) +
			     strlen( dirInfo->d_name ) +
			     2 );
	  
	  if( pathName == NULL )
	    {
	      SET_ERROR( C_EOSERROR );
	      return( RET_ERROR );
	    }
	  
	  sprintf( pathName,"%s/%s",dirName, dirInfo->d_name );
	  
	  if( S_ISDIR( fileStat.st_mode ) == TRUE  && recurs == TRUE )
	    {
	      
	      if( ForeachFile( pathName, fileProc, recurs, closure ) != 0 )
		{
		  return( RET_ERROR );
		}
	      
	      free( pathName );
	      
	    }
	  else
	    {
	      if( fileProc( pathName, closure ) != 0 )
		{
		  return( RET_ERROR );
		}
	    }
	}
    }
  else
    {
      if( fileProc( dirName, closure ) != 0 )
	{
	  return( RET_ERROR );
	}
    }

  return( RET_SUCCEED );
}
		  
