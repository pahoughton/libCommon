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
 * Revision 1.1  1994/06/17  18:07:28  houghton
 * Cool new Logger function
 *
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";

#include <stdio.h>

#include "_Common.h"

char * LogLevelNames[] =
{
  "NONE",
  "ERROR",
  "WARN",
  "USER_1",
  "USER_2",
  "INFO",
  "TEST",
  "DEBUG",
  "FUNCT",
  "ALL",
  NULL
};

LogBit  LogLevels[] =
{
  LOG_NONE,
  LOG_ERROR,
  LOG_WARN,
  LOG_USR1,
  LOG_USR2,
  LOG_INFO,
  LOG_TEST,
  LOG_DEBUG,
  LOG_FUNCT,
  LOG_ALL
};
    


int
LogLevelFromString(
    const char * levelString
    )
{

  int level = 0;
  int l;

  for( l = 0; LogLevelNames[l] != 0; l++ )
    {
      if( strstr( levelString, LogLevelNames[l] ) != NULL )
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
