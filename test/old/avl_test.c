/**
* avl_test.c -- C source file to test the object-oriented AVL Tree
*               Library (dont forget to link with "avl.o").
*
* Created 03/01/89 by Brad Appleton
*
* ^{Mods:* }
* 
* Fri Jul 14 13:54:34 1989, Rev 1.0, brad(0165)
* 
**/
  
#ifndef DEBUG
#  define DBG(x)    /* x */
#else
#  define DBG(x)    x
#endif

#define  LEFT_SUBTREE_EMPTY(nd)   ( (nd == IS_RBRANCH) || (nd == IS_LEAF) )
#define  RIGHT_SUBTREE_EMPTY(nd)  ( (nd == IS_LBRANCH) || (nd == IS_LEAF) )

#include	<stdio.h>
#include	"avl.h"
#include	"testvals.h"
  
static int intcmp( i1, i2 )	int *i1, *i2;	{ return ( *i1 - *i2 ); }

static void avlprint( 
    void  *dataptr,
    VISIT order,
    NODE  node,
    int   level,
    short bal,
    void * closure )
    
{
    int   len = ((level - 1) * 5), *key;
    char  fmt[9];

    key = (int *) dataptr;  
    if ( len )	sprintf( fmt, "%%-%ds", len );
    else	strcpy( fmt, "%-1s" );

    if ( node == IS_NULL )   printf( "NULL_TREE\n" );

    else {
        if ( (order == PREORDER)  &&  LEFT_SUBTREE_EMPTY( node ) )
            { printf( fmt, " " );  printf( "     ==NULL==\n" ); }

        if ( order == INORDER )
	    { printf( fmt, " " ); printf( "%d:%d\n", *key, bal ); }

        if ( (order == POSTORDER)  &&  RIGHT_SUBTREE_EMPTY( node ) )
	    { printf( fmt, " " );  printf( "     ==NULL==\n" ); }
    }/* else */
}/* avlprint */  


static void avlfreedata( 
    void *dataptr,
    void * closure )
{
    int key = (int) *( (int *) dataptr );

    printf( "freeing avl-node for key: %d ...\n", key );
    
}/* avlfreedata */


main()
{
    AVL_TREE  mytree;
    int       i;
  
    mytree = avlinit( intcmp, NULL, NULL, NULL );
  
    for ( i = 0 ; i < NUM_VALS ; i++ )  {
        printf( "+++ inserting key #%d: %d +++\n", i, TestVals[i] );
        avlins( mytree, (void *) &( TestVals[i] ) );
        DBG( avlwalk( mytree, avlprint, RIGHT_TO_LEFT ); )
    }/* for */
  
    printf( "------------------ contents of tree ----------------\n" );
    avlwalk( mytree, avlprint, RIGHT_TO_LEFT, NULL );
    printf( "----------------------------------------------------\n" );

    for ( i = 0 ; i < NUM_DELS ; i++ )  {
        printf( "+++ deleting key #%d: %d +++\n", i, DelVals[i] );
        DBG( avlwalk( mytree, avlprint,  RIGHT_TO_LEFT, NULL ); )
        avldel( mytree, (void *) &( DelVals[i] ) );
    }/* for */
  
    printf( "------------------ contents of tree ----------------\n" );
    avlwalk( mytree, avlprint, RIGHT_TO_LEFT, NULL );
    printf( "----------------------------------------------------\n" );
    printf( "Deallocating tree ...\n" );
    avldispose( &mytree, avlfreedata, LEFT_TO_RIGHT, NULL );
    printf( "DONE!" );
    exit( 0 );
}/* main */

