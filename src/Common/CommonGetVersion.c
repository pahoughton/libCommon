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
 * Revision 1.2  1994/06/17  18:03:57  houghton
 * Cleanup for beta release.
 *
 * Revision 1.1  1994/01/31  14:06:13  houghton
 * Add avl and some other minor functions
 *
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";


#ifdef OPENVMS
const char _CommonVersionString[] =
{
  "libCommon Version:Beta 0.9 				\
   Compiled: __DATE__ __TIME__ 				\
   CVS Tag:$Id$				"
};
#else
const char _CommonVersionString[] = 
{
      "libCommon Version: BETA 0.9\n"
      "Compiled: " __DATE__ " " __TIME__ "\n"
      "CVS Tag: BETA_0_9 $Id$ \n"
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
