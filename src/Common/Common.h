#ifndef _COMMON_H_
#define _COMMON_H_
/*********************************************************************
 *
 * Title:            Common.h
 *
 * Description:
 *
 *	Common / Generic C Functions
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
 * $Log$
 * Revision 1.3  1994/02/02  14:38:25  houghton
 * Had to rename error to LibError because of a conflicts with other
 * symbols. Minor mods to other files
 *
 * Revision 1.2  1994/01/31  14:06:12  houghton
 * Add avl and some other minor functions
 *
 *********************************************************************/

#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#ifndef ON
#define ON 1
#define OFF 0
#endif

#ifndef NO
#define NO  	0
#define YES 	1
#endif

#ifndef Bool
#define Bool int   /* wanted to do an enum, but to common */
#endif

typedef enum
{
  RET_SUCCEED,
  RET_DATA,
  RET_DONE,
  RET_ERROR,
  RET_FATAL
}   Ret_Status;


/*
 *Remember to add the descriptions for new errors in
 * ErrorString.c
 */
typedef enum
{
  C_ENONE,
  C_EOSERROR,
  C_ERANGE,
  C_EBADPARAM,
  C_EAPP,		/* Application Error */  
  C_EUNDEFINED
} CommonErrorType;

extern char *	    	CommonErrFile;
extern int  	    	CommonErrLine;
extern int  	    	CommonOsErr;
extern CommonErrorType 	CommonErrno;
extern int		CommonAppErrno;

#define SET_ERROR( _err_ )						\
    CommonErrFile = __FILE__; CommonErrLine = __LINE__;			\
    CommonErrno = _err_;						\
    CommonOsErr = ((_err_ == C_EOSERROR ) ? errno : 0);
 
#define SET_APP_ERROR( _err_ )	\
    SET_ERROR( C_EAPP );	\
    CommonAppErrno = _err_;     \

#define LIB_ERROR( _close_, _str_ )    \
    LibError( CommonErrno, CommonAppErrno, _close_, _str_ )


#define CharToInt( _d_ ) \
( ( _d_ <= '9' ) ? _d_ - '0' : ( 10 + ( (_d_ | 0x20) - 'a' ) ))

#define IsBaseDigit( _d_, _b_ ) (CharToInt(_d_) >= 0 && CharToInt(_d_) < _b_ )


Ret_Status ArgEnvInt( int * argc, char *argv[],
	       const char * argid, const char * envVar,
	       int min, int max, int * paramVar );

Ret_Status ArgEnvBool( int * argc, char *argv[],
		const char * argid, const char * envVar,
	        int * paramVar );

Ret_Status ArgEnvString( int * argc, char *argv[],
		  const char * argid, const char * envVar,
	          char ** paramVar );

time_t	Difftm( struct tm * t1, struct tm * t2 );
char * strlwr( char * str );

int  StringToInt( const char * str, int base, int len );

void CenterLine( char * dest, const char * src, int width );
void StripSpaces( char * buffer );

#define basename(_path_) (strrchr( _path_, '/' ) + 1)

Ret_Status ForeachFile(
    const char *    name,
    Ret_Status      (*fileProc)( const char * name, void * closure ),
    Bool    	    recurs,
    void *  	    closure 
    );

/*
 * AVL tree types and  functions
 */

typedef void * AvlTree;

typedef  enum  {       /* definition of traversal type */
  AVL_PREORDER,
  AVL_INORDER,
  AVL_POSTORDER
}  AvlVisit;

typedef  enum  {       /* definition of sibling order type */
  AVL_LEFT_TO_RIGHT,
  AVL_RIGHT_TO_LEFT
}  AvlSiblingOrder;

typedef  enum  {       /* definition of node type */
  AVL_IS_TREE,
  AVL_IS_LBRANCH,
  AVL_IS_RBRANCH,
  AVL_IS_LEAF,
  AVL_IS_NULL
} AvlNodeType;


AvlTree AvlInit( int    (*compare)(const void * data1,
				   const void * data2,
				   AvlNodeType nd),
		 void * (*getMem)( size_t size, void * closure ),
		 void   (*freeMem)( void * data, void * closure ),
		 void * memClosure );

/* for attaching to a memory mapped tree */

AvlTree AvlAttach( void * avlRoot,
		   int      (*compare)(const void * data1,
				       const void * data2,
				       AvlNodeType nd),
		   void *   (*getMem)( size_t size, void * closure ),
		   void     (*freeMem)( void * data, void * closure ),
		   void *   memClosure );

void * AvlGetRoot( AvlTree  tree );

void * AvlAdd( AvlTree tree, void * key );
void * AvlDel( AvlTree tree, void * key );
void * AvlFind( AvlTree tree, const void * key );
unsigned long    AvlCount( AvlTree tree );

void AvlDispose( AvlTree * treeptr,
		 void      (*action)( void * data, void * closure ),
  		 AvlSiblingOrder  sibling_order,
		 void *	   closure );
void AvlWalk( AvlTree      tree,
	      void          (*action)( void * data, AvlVisit order,
				       AvlNodeType node, int level,
				       short bal, void * closure),
	      AvlSiblingOrder  sibling_order,
	      void * 	   closure );
void * AvlDelMin( AvlTree  tree );
void * AvlFindMin( AvlTree  tree );
void * AvlDelMax( AvlTree  tree );
void * AvlFindMax ( AvlTree  tree );


/*
 * Error processing Functions
 */
void SetErrorHandler( void (*errorHandler_)( CommonErrorType error,
					     int appErrno,
					     void * closure,
					     const char * mesg ),
		      void * closure );

void LibError( CommonErrorType error,
	       int appErrno,
	       void * closure,
	       const char * message, ... );

const char * ErrorString( CommonErrorType error );

const char * CommonGetVersion( void );


#if defined( NeXT )
char * strdup( const char *);
#endif

#ifdef __cplusplus
};
#endif


#endif

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
