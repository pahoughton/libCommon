/*********************************************************************
 *
 * Title:            LogLevelFromString.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (houghton@cworld)
 *
 * Start Date:	    07/06/94 09:33
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/10/29  12:01:17  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:24  houghton
 * Move to Version 2.0
 *
 * Revision 1.2  1994/08/15  19:57:05  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.1  1994/06/17  18:07:28  houghton
 * Cool new Logger function
 *
 *
 *********************************************************************/
#include "_Common.h"
#include <string.h>

COMMON_VERSION(
  LogLevelFromString,
  "$Id$");


LogLevelBit  LogLevels[] =
{
  LOG_NONE,
  LOG_ERROR,
  LOG_WARN,
  LOG_APP1,
  LOG_APP2,
  LOG_APP3,
  LOG_APP4,
  LOG_APP5,
  LOG_APP6,
  LOG_WCF1,
  LOG_WCF2,
  LOG_WCF3,
  LOG_WCF4,
  LOG_INFO,
  LOG_TEST,
  LOG_DEBUG,
  LOG_FUNCT,
  LOG_ALL
};
    
extern const char * _CLogLevelNames[];	/* LogLevelString.c */


int
LogLevelFromString( const char * levelString )
{

  int level = 0;
  int l;

  for( l = 0; _CLogLevelNames[l] != 0; l++ )
    {
      if( strstr( levelString, _CLogLevelNames[l] ) != NULL )
	{
	  level |= LogLevels[l];
	}
    }

  return( level );
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
