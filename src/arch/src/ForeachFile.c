/*********************************************************************
 *
 * Title:            ForeachFile.c
 *
 * Description:
 *
 *	
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
 * Revision 1.1  1994/01/31  14:06:14  houghton
 * Add avl and some other minor functions
 *
 *
 *********************************************************************/
static const char RcsId[] =
{"$Id$"};

#define _ALL_SOURCE
#include <Common.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

Ret_Status
ForeachFile(
    const char *    name,
    Ret_Status      (*fileProc)( const char * name, void * closure ),
    Bool    	    recurs,
    void *  	    closure 
    )
{
  

  struct stat	fileStat;
  
  
  if( stat( name, &fileStat ) != 0 )
    {
      SET_ERROR( C_EOSERROR );
      return( RET_ERROR );
    }
  
  if( S_ISDIR( fileStat.st_mode ) == TRUE )
    {
      
      DIR	    	*dir;
      struct dirent	*dirInfo;
      
      if( (dir = opendir( name ) ) == NULL )
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
	  pathName = malloc( strlen( name ) +
			     strlen( dirInfo->d_name ) +
			     2 );
	  
	  if( pathName == NULL )
	    {
	      SET_ERROR( C_EOSERROR );
	      return( RET_ERROR );
	    }
	  
	  sprintf( pathName,"%s/%s",name, dirInfo->d_name );
	  
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
      if( fileProc( name, closure ) != 0 )
	{
	  return( RET_ERROR );
	}
    }

  return( RET_SUCCEED );
}
		  
	  
	
  



/**
 *             This software is the sole property of
 *
 *                 The Williams Companies, Inc.
 *                       1 Williams Center
 *                         P.O. Box 2400
 *                      Tulsa, Oklahoma 74102
 *
 *        Copyright (c) 1993 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/

