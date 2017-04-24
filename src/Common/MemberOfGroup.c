/*********************************************************************
 *
 * Title:            MemberOfGroup.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    08/04/94 10:20
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/10/29 13:33:57  houghton
 * Initial Linux Build of Version 2
 *
 * Revision 2.0  1995/10/28  17:35:48  houghton
 * Move to Version 2.0
 *
 * Revision 1.2  1994/08/15  19:57:08  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.1  1994/08/15  19:42:20  houghton
 * Add ArgEnvFlage, ArgEnvLong, CanExecute, FindPath and MemberOfGroup
 * functions
 *
 *
 *********************************************************************/
#include "_Common.h"

#include <unistd.h>
#include <limits.h>
#include <sys/types.h>

COMMON_VERSION(
  MemberOfGroup,
  "$Id$");

BOOL
MemberOfGroup( gid_t grp )
{
  gid_t groups[ NGROUPS_MAX ];
  int	count;
  int	i;

  if( ( grp == getegid() ) || ( grp == getgid() ) )
    {
      return( 1 );
    }
    
  if( (count = getgroups( NGROUPS_MAX, groups ) ) == 0 )
    {
      return( 0 );
    }

  for( i = 0; i < count; i++ )
    {
      if( grp == groups[i] )
	{
	  return( 1 );
	}
    }

  return( 0 );
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
