/*********************************************************************
 *
 * Title:            tLOGIT.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/21/95 14:19
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/12/02 02:13:56  houghton
 * Initial Version.
 *
 *
 *********************************************************************/

#include <Common.h>


BOOL
tLOGIT( void )
{
  LOGIT( LOG_ERROR, ("Test LOGIT LOG_ERROR %d\n",1 ) );

  LOGIT( LOG_TEST, ("BAD BAD BAD\n" ));

  return( TRUE );
}

