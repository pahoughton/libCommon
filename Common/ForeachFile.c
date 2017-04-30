/* 1993-07-23 (cc) paul4hough@gmail.com

   Execute a function (fileProc) for each file in a dirctory
   tree. If recurs is true, walk down sub dirs.
*/
#include "_Common.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

int
ForeachFile(
  const char * dirName,
  int          (*fileProc)( const char * name, void * closure ),
  BOOL    	 recurs,
  void *  	 closure
  )
{

  struct stat	fileStat;

  if( stat( dirName, &fileStat ) != 0 )
    {
      return( errno );
    }

  if( S_ISDIR( fileStat.st_mode ) == TRUE )
    {

      DIR	    	*dir;
      struct dirent	*dirInfo;

      if( (dir = opendir( dirName ) ) == NULL )
	{
	  return( errno );
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
	      return( errno );
	    }

	  sprintf( pathName,"%s/%s",dirName, dirInfo->d_name );

	  if( S_ISDIR( fileStat.st_mode ) == TRUE  && recurs == TRUE )
	    {

	      int ret = ForeachFile( pathName, fileProc, recurs, closure );
	      free( pathName );
	      if( ret )
		return( ret );

	    }
	  else
	    {
	      int ret = fileProc( pathName, closure );
	      if( ret )
		return( ret );
	    }
	}
    }
  else
    {
      int ret = fileProc( dirName, closure );
      if( ret )
	return( ret );
    }

  return( 0 );
}
