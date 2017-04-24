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
 * Revision 2.1  1995/10/29 13:33:55  houghton
 * Initial Linux Build of Version 2
 *
 * Revision 2.0  1995/10/28  17:35:46  houghton
 * Move to Version 2.0
 *
 * Revision 1.3  1995/02/13  15:34:13  houghton
 * New functions and many enhancements to existing functions.
 *
 * Revision 1.2  1994/08/15  19:56:59  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.1  1994/08/15  19:42:19  houghton
 * Add ArgEnvFlage, ArgEnvLong, CanExecute, FindPath and MemberOfGroup
 * functions
 *
 *
 *********************************************************************/
#include "_Common.h"

#include <unistd.h>
#include <sys/stat.h>

COMMON_VERSION(
  CanExecute,
  "$Id$");

BOOL
CanExecute( const char * fileName )
{

  struct stat st;

  if( stat( fileName, &st ) == 0 &&
      ( ( st.st_uid == geteuid() && ( st.st_mode & S_IXUSR ) ) ||
	( MemberOfGroup( st.st_gid ) && ( st.st_mode & S_IXGRP ) ) ||
	( st.st_mode & S_IXOTH ) ) )
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
