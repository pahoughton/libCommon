/*********************************************************************
 *
 * Title:            CommonGetVersion.c
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
 * Programmer:	    Paul Houghton (pah)
 *
 * Start Date:	    01/25/94 12:48
 *
 * Modification History:
 *
 * $Log$
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";

const char _CommonVersionString[] = 
{
      "libCommon Version: BETA 0.3\n"
      "Compiled: " __DATE__ " " __TIME__ "\n"
      "CVS Tag: NONE  $Id$ \n"
};


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
