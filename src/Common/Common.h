/*********************************************************************
 *
 * Title:            Common.h
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
 * Start Date:	    09/03/93 10:04
 *
 * Modification History:
 *
 *
 *********************************************************************/


#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef ON
#define ON 1
#endif

#ifndef OFF
#define OFF 0
#endif


typedef enum
{
  E_NONE,
  E_OSERROR,
  E_RANGE,
  E_BADARG,
  E_BADPARAM,
  E_UNDEFINED
} CommonErrorType;

extern char *	    	ErrFile;
extern int  	    	ErrLine;
extern int  	    	OsErr;
extern CommonErrorType 	Errno;


int ArgEnvInt( int * argc, char *argv[], char * argid, char * envVar,
	       int min, int max, int * paramVar );

int ArgEnvBool( int * argc, char *argv[], char * argid, char * envVar,
	        int * paramVar );

int ArgEnvString( int * argc, char *argv[], char * argid, char * envVar,
	          char ** paramVar );



extern char * strdup( const char *);



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
