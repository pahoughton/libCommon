/*********************************************************************
 *
 * Title:            CanExecute.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    08/04/94 10:14
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.1  1994/08/15  19:42:19  houghton
 * Add ArgEnvFlage, ArgEnvLong, CanExecute, FindPath and MemberOfGroup
 * functions
 *
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "_Common.h"

Bool
CanExecute( const char * fileName )
{

  struct stat st;

  if( stat( fileName, &st ) == 0 &&
      ( ( st.st_uid == geteuid() && ( st.st_mode & S_IXUSR ) ) ||
	( MemberOfGroup( st.st_gid ) && ( st.st_mode & S_IXGRP ) ) ||
	( st.st_mode & S_IXUSR ) ) )
    {
      return( TRUE );
    }
  
  return( FALSE );
  
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
