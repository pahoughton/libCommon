/*********************************************************************
 *
 * Title:            StringTest.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Dora Potluri x561-6131 - (dpotluri@shoe.wiltel.com)
 *
 * Start Date:	    07/19/94 13:57
 *
 * Modification History:
 *
 * $Log$
 *
 *********************************************************************/
static const char RcsId[] =
"$Id$";

#include <Common.h>

#include <stdio.h>




Ret_Status
StringTest()
{
  char * upperCase = "THIS IS UPPER CASE STRING";
  char * lowerCase = "this is upper case string";
  char * duplicateString = NULL;
  char   buffer[60];

    
  duplicateString = (char *) strdup( upperCase );
  
  if ( NULL == duplicateString )
    {
      printf("Failed to Duplicate the string \n" );
      return( RET_ERROR );
    }

   strcpy( duplicateString, upperCase );

  if ( strcmp( upperCase, duplicateString ) != 0 )
    {
      printf("Failed to compare strings \n" );
      return( RET_ERROR );
    }

  strlwr( duplicateString );
  if ( strcmp( lowerCase, duplicateString ) != 0 )
    {
      printf("Failed to test strlwr  \n" );
      return( RET_ERROR );
    }

  strupr( duplicateString );
  if ( strcmp( upperCase, duplicateString ) != 0 )
    {
      printf("Failed to test strupr  \n" );
      return( RET_ERROR );
    }

  if ( CenterLine( buffer, duplicateString, sizeof(buffer) ) == NULL )
    {
      printf("Failed to test CenterLine \n" );
      return( RET_ERROR );
    }

  StripSpaces( buffer );

  if ( strcmp( buffer, duplicateString ) != 0 )
    {
      printf("Failed to test StripSpaces \n" );
      return( RET_ERROR );
    }

  free( duplicateString );
  
  TestOutput("Successfully Tested String Functions \n" );
  
  return( RET_SUCCEED );

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
