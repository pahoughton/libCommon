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
static const char * RcsId =
"$Id$";


#ifdef OPENVMS
const char _CommonVersionString[] =
{
  "libCommon Version: Prod 1.0
   Compiled: __DATE__ __TIME__ 				\
   CVS Tag: PROD_1_0 $Id$				"
};
#else
const char _CommonVersionString[] = 
{
      "libCommon Version: PROD 1.0\n"
      "Compiled: " __DATE__ " " __TIME__ "\n"
      "CVS Tag: PROD_1_0 $Id$ \n"
};
#endif

const char *
CommonGetVersion( void )
{
  return( _CommonVersionString );
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
