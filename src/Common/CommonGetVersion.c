/*********************************************************************
 *
 * Title:            CommonGetVersion.c
 *
 * Description:
 *
 *   Return a version String pointer.
 *
 * Error Handling:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton (pah)
 *
 * Start Date:	    01/25/94 12:48
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.3  1996/05/03 16:09:27  houghton
 * Cleanup for AIX port.
 *
 * Revision 2.2  1995/11/10 00:46:11  houghton
 * Fixed CVS Tag value
 *
 * Revision 2.1  1995/10/28  19:11:40  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:16  houghton
 * Move to Version 2.0
 *
 * Revision 1.5  1994/08/15  19:57:00  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.4  1994/08/15  19:40:17  houghton
 * Cleanup; Rating QA1 Checkin
 *
 * Revision 1.3  1994/06/20  15:28:38  dpotluri
 * LibCommon Port to OPENVMS
 *
 * Revision 1.2  1994/06/17  18:03:57  houghton
 * Cleanup for beta release.
 *
 * Revision 1.1  1994/01/31  14:06:13  houghton
 * Add avl and some other minor functions
 *
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  CommonGetVersion,
  "$Id$" );


const char CommonVersion[] =
#if !defined( OPENVMS )

  "@(#) " COMMON_PRJ_NAME " - " COMMON_PRJ_VER "\n"			      
  "    Compiled: " __DATE__ " "__TIME__ "\n"
  "    CVS Tag: " COMMON_PRJ_VER_TAG "\n"
  "    $Id$ "; 

#else

"@(#) libCommon - 2.00.00.b.02\n    Compiled: after $Date$\n    CVS Tag: BETA_2_0\n    $Id$\n";

#endif


const char *
CommonGetVersion( void )
{
  return( CommonVersion );
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
