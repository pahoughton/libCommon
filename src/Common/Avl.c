/**
*
* avl.c -- C source file for avl trees. Contains the auxillary routines
*          and defines for the avl tree functions and user interface and
*          includes all the necessary public and private routines
*
* Created 03/01/89 by Brad Appleton
*
* ^{Mods:* }
* 
* Fri Jul 14 13:53:42 1989, Rev 1.0, brad(0165)
*
* $Log$
 * Revision 1.3  1994/06/17  18:04:03  houghton
 * Cleanup for beta release.
 *
*
**/

static const char RcsId[] =
{"$Id$"};

#include <stdio.h>
#include <stdlib.h>

#include "_Common.h"
#include "avl_typs.h"    /* private types for avl trees */

#define AVL_VERSION	0x41766c01	/* version id Avl1 */

  
	/* some defines for debugging purposes */
#ifdef NDEBUG
#define DBG(x)		/* x */
#else
#define DBG(x)		x
#endif




static void *
avlMalloc(
    size_t size,
    void * closure
    )
{
  return( malloc( size ) );
}

static void
avlFree(
    void * data,
    void * closure
    )
{
  free( data );
}

/*
* new_node() -- get space for a new node and its data;
*               return the address of the new node
*/
static   AVLtree
new_node( AVLdescriptor * avlDesc, void * data )
{
  AVLtree  	   node;
  
  node = avlDesc->getMem( sizeof( AVLnode ), avlDesc->memClosure );
  
  if( node != NULL )
    {      
      node->data = data;
      node->bal = BALANCED;
      node->subtree[ LEFT ] = node->subtree[ RIGHT ] = NULL_TREE;
    }	
  return node;
}/* new_node */


/*
* free_node()  --  free space for a node and its data!
*                  reset the node pointer to NULL
*/
static    void
free_node( AVLdescriptor * avlDesc,  AVLtree * rootp )
{
  
  avlDesc->freeMem( *rootp, avlDesc->memClosure );
  *rootp = NULL_TREE;
  
}/* free_node */
  
  
/*
* node_type() -- determine the number of null pointers for a given
*                node in an AVL tree, Returns a value of type AvlNodeType
*                which is an enumeration type with the following values:
*
*                  AVL_IS_TREE     --  both subtrees are non-empty
*                  AVL_IS_LBRANCH  --  left subtree is non-empty; right is empty
*                  AVL_IS_RBRANCH  --  right subtree is non-empty; left is empty
*                  AVL_IS_LEAF     --  both subtrees are empty
*                  AVL_IS_NULL     --  given tree is empty
*/
static     AvlNodeType
node_type( AVLtree    tree )
{
  if ( tree == NULL_TREE )
    return  AVL_IS_NULL;
  
  else if ( (tree -> subtree[ LEFT ] != NULL_TREE)  &&
	    (tree -> subtree[ RIGHT ] != NULL_TREE) )
    return  AVL_IS_TREE;
  
  else if ( tree -> subtree[ LEFT ] != NULL_TREE )
    return  AVL_IS_LBRANCH;
  
  else if ( tree -> subtree[ RIGHT ] != NULL_TREE )
    return  AVL_IS_RBRANCH;
  
  else
    return  AVL_IS_LEAF;
}/* node_type */



/************************************************************************
*	PRIVATE functions for manipulating AVL trees
*
*  This following defines a set of routines for creating, maintaining, and
*  manipulating AVL Trees as an Abtract Data Type. The routines in this
*  file that are accessible (through the avl tree user-interface) to other
*  files to allow other programmers to:
*
*       Insert, Delete, and Find a given data item from a Tree.
*
*       Delete and Find the minimal and Maximal items in a Tree.
*
*       Walk through every node in a tree performing a giving operation.
*
*       Walk through and free up space for every node in a tree while performing
*       a given operation on the data items as they are encountered.
************************************************************************/


/************************************************************************
*	routines used to find the minimal and maximal elements
*       (nodes) of an AVL tree.
************************************************************************/
  
/*
* avl_min() -- compare function used to find the minimal element in a tree
*/
static int
avl_min( elt1, elt2, nd_typ )
const void  *elt1, *elt2;
AvlNodeType  nd_typ;
{
  if ( nd_typ == AVL_IS_RBRANCH  ||  nd_typ == AVL_IS_LEAF )
    return   0;   /* left subtree is empty -- this is the minimum */
  
  else  return  -1;   /* keep going left */
}/* avl_min */


/*
* avl_max() -- compare function used to find the maximal element in a tree
*/
static int avl_max( elt1, elt2, nd_typ )
const void  *elt1, *elt2;
AvlNodeType  nd_typ;
{
  if ( nd_typ == AVL_IS_RBRANCH  ||  nd_typ == AVL_IS_LEAF )
    return  0;   /* right subtree is empty -- this is the maximum */
  
  else  return  1;   /* keep going right */
}/* avl_max */


/************************************************************************
*	Routines to perform rotations on AVL trees
************************************************************************/

/*
* rotate_once()  --  rotate a given node in the given direction
*                    to restore the balance of a tree
*/
static     short
rotate_once(
    AVLtree    *rootp,
    DIRECTION  dir
    )
{
  DIRECTION   other_dir = OPPOSITE( dir );	/* opposite direction to "dir" */
  AVLtree     old_root  = *rootp;		/* copy of original root of tree */
  short	ht_unchanged;			/* true if height unchanged */
  
  ht_unchanged = ( (*rootp) -> subtree[ other_dir ] -> bal ) ? FALSE : TRUE;
  
      /* assign new root */
  *rootp = old_root -> subtree[ other_dir ];
  
      /* new-root exchanges it's "dir" subtree for it's parent */
  old_root -> subtree[ other_dir ]   =   (*rootp) -> subtree[ dir ];
  (*rootp) -> subtree[ dir ]         =   old_root;
  
      /* update balances */
  old_root -> bal = -( dir == LEFT ? --( (*rootp) -> bal ) : ++( (*rootp) -> bal )  );
  
  return  ht_unchanged;
}/* rotate_once */
  
  
/*
* rotate_twice()  --  rotate a given node in the given direction
*                     and then in the opposite direction
*                     to restore the balance of a tree
*/
static     void
rotate_twice( 
    AVLtree    *rootp,
    DIRECTION  dir
    )
{
  DIRECTION   other_dir		= OPPOSITE( dir );
  AVLtree     old_root		= *rootp,
    old_other_dir_subtree	= (*rootp) -> subtree[ other_dir ];
  
      /* assign new root */
  *rootp = old_root -> subtree[ other_dir ] -> subtree[ dir ];
  
      /* new-root exchanges it's "dir" subtree for it's grandparent */
  old_root -> subtree[ other_dir ]  =   (*rootp) -> subtree[ dir ];
  (*rootp) -> subtree[ dir ]        =   old_root;
  
      /* new-root exchanges it's "other-dir" subtree for it's parent */
  old_other_dir_subtree -> subtree[ dir ]	= (*rootp) -> subtree[ other_dir ];
  (*rootp) -> subtree[ other_dir ]		= old_other_dir_subtree;
  
      /* update balances */
  (*rootp) -> subtree[ LEFT ] -> bal   =  -MAX( (*rootp) -> bal, 0 );
  (*rootp) -> subtree[ RIGHT ] -> bal  =  -MIN( (*rootp) -> bal, 0 );
  (*rootp) -> bal                      =  0;
  
}/* rotate_twice */


/************************************************************************
*	                Rebalance an AVL tree
************************************************************************/

/*
* balance()  --  determines and performs the  sequence of rotations needed
*                   (if any) to restore the balance of a given tree.
*
*     Returns 1 if tree height changed due to rotation; 0 otherwise
*/
static    short
balance( AVLtree    *rootp )
{
  short  special_case = FALSE;
  
  if ( LEFT_IMBALANCE( *rootp )  )  {   /* need a right rotation */
    if ( (*rootp) -> subtree[ LEFT ] -> bal  ==  RIGHT_HEAVY )
      rotate_twice( rootp, RIGHT );    /* double RL rotation needed */
    
    else	/* single RR rotation needed */
      special_case = rotate_once( rootp, RIGHT );
  }/* if */
  
  else if ( RIGHT_IMBALANCE( *rootp )  )  {   /* need a left rotation */
    if ( (*rootp) -> subtree[ RIGHT ] -> bal  ==  LEFT_HEAVY )
      rotate_twice( rootp, LEFT );     /* double LR rotation needed */
    
    else	/* single LL rotation needed */
      special_case = rotate_once( rootp, LEFT );
  }/* elif */
  
  else  return  HEIGHT_UNCHANGED;	/* no rotation occurred */
  
  return  ( special_case ) ? HEIGHT_UNCHANGED : HEIGHT_CHANGED;
}/* balance */


/************************************************************************
*	Routines to:	Find an item in an AVL tree
*			Insert an item into an AVL tree
*			Delete an item from an AVL tree
************************************************************************/

/*
* avl_find() -- find an item in the given tree
*
*   PARAMETERS:
*                data       --  a pointer to the key to find
*                rootp      --  a pointer to an AVL tree
*                compar     --  name of a function to compare 2 data items
*/
static      void *
avl_find( 
    void      *data,
    AVLtree   tree,
    int       (*compar)( void * data1, void * data2, AvlNodeType nd )
    )
{
  AvlNodeType       nd_typ = node_type( tree );
  int        cmp;
  
  while ( (tree != NULL_TREE) && 
          (cmp = (*compar)( data, tree -> data, nd_typ ))  )
    tree = tree -> subtree[ (cmp < 0) ? LEFT : RIGHT ];
  
  return  ( tree == NULL_TREE ) ? NULL : tree -> data;
}/* avl_find */
  
 
/*
* avl_insert() -- insert an item into the given tree
*
*   PARAMETERS:
*                data       --  a pointer to a pointer to the data to add;
*                               On exit, *data is NULL if insertion succeeded,
*                               otherwise address of the duplicate key
*                rootp      --  a pointer to an AVL tree
*                compar     --  name of the function to compare 2 data items
*/
static     short avl_insert(
    AVLdescriptor * avlDesc,
    void     **data,
    AVLtree  *rootp,
    int      (*compar)( const void * data1, const void * data2, AvlNodeType nd)
    )
{
  short increase;
  int   cmp;
  
  if ( *rootp == NULL_TREE )  {  /* insert new node here */
    *rootp = new_node( avlDesc, *data );
    *data  = NULL;     /* set return value in data */
    return  HEIGHT_CHANGED;
  }/* if */
  
      /* compare data items */
  cmp = (*compar)( *data, (*rootp) -> data, node_type( *rootp ) );  
  
  if ( cmp < 0 )  {  /* insert into the left subtree */
    increase =  -avl_insert( avlDesc, data, &( (*rootp) -> subtree[ LEFT ] ), compar );
    if ( *data != NULL )     return  HEIGHT_UNCHANGED;
  }/* elif */
  
  else if ( cmp > 0 )  {  /* insert into the right subtree */
    increase =  avl_insert( avlDesc, data, &( (*rootp) -> subtree[ RIGHT ] ), compar );
    if ( *data != NULL )     return  HEIGHT_UNCHANGED;
  }/* elif */
  
  else  {   /* data already exists */
    *data = (*rootp) -> data;   /* set return value in data */
    return  HEIGHT_UNCHANGED;
  } /* else */
  
  (*rootp) -> bal += increase;    /* update balance factor */
  
      /************************************************************************
       * re-balance if needed -- height of current tree increases only if its
       * subtree height increases and the current tree needs no rotation.
       ************************************************************************/
  if ( increase  &&  (*rootp) -> bal )
    return  (  1 - balance( rootp )  );
  else
    return  HEIGHT_UNCHANGED;
}/* avl_insert */


/*
* avl_delete() -- delete an item from the given tree
*
*   PARAMETERS:
*                data       --  a pointer to a pointer to the key to delete
*                               On exit, *data points to the deleted data item
*                               (or NULL if deletion failed).
*                rootp      --  a pointer to an AVL tree
*                compar     --  name of function to compare 2 data items
*/
static     short
avl_delete(
    AVLdescriptor * avlDesc,    
    void      **data,
    AVLtree   *rootp,
    int       (*compar)( const void * data1, const void * data2, AvlNodeType nd )
    )
{
  short      decrease = 0;
  int        cmp;
  AVLtree    old_root  = *rootp;
  AvlNodeType       nd_typ    = node_type( *rootp );
  DIRECTION  dir       = (nd_typ == AVL_IS_LBRANCH) ? LEFT : RIGHT;
  
  if ( *rootp == NULL_TREE )  {  /* data not found */
    *data = NULL;    /* set return value in data */
    return  HEIGHT_UNCHANGED;
  }/* if */
  
  cmp = compar( *data, (*rootp) -> data, nd_typ );   /* compare data items */
  
  if ( cmp < 0 )  {  /* delete from left subtree */
    decrease =  -avl_delete( avlDesc, data, &( (*rootp) -> subtree[ LEFT ] ), compar );
    if ( *data == NULL )     return  HEIGHT_UNCHANGED;
  }/* elif */
  
  else if ( cmp > 0 )  {  /* delete from right subtree */
    decrease =  avl_delete( avlDesc, data, &( (*rootp) -> subtree[ RIGHT ] ), compar );
    if ( *data == NULL )     return  HEIGHT_UNCHANGED;
  }/* elif */
  
      /************************************************************************
       *  At this point we know that if "cmp" is zero then "*rootp" points to
       *  the node that we need to delete.  There are three cases:
       *
       *     1) The node is a leaf.  Remove it and return.
       *
       *     2) The node is a branch (has only 1 child). Make "*rootp"
       *        (the pointer to this node) point to the child.
       *
       *     3) The node has two children. We swap data with the successor of
       *        "*rootp" (the smallest item in its right subtree) and delete
       *        the successor from the right subtree of "*rootp".  The
       *        identifier "decrease" should be reset if the subtree height
       *        decreased due to the deletion of the sucessor of "rootp".
       ************************************************************************/
  
  else  {  /* cmp == 0 */
    *data = (*rootp) -> data;  /* set return value in data */
    
    switch ( nd_typ )  {  /* what kind of node are we removing? */
    case  AVL_IS_LEAF :
      free_node( avlDesc, rootp );  /* free the leaf, its height     */
      return  HEIGHT_CHANGED;       /* changes from 1 to 0, return 1 */
      
    case  AVL_IS_RBRANCH :       /* only child becomes new root */
    case  AVL_IS_LBRANCH :
      *rootp = (*rootp) -> subtree[ dir ];
      free_node( avlDesc, &old_root );      /* free the deleted node */
      return  HEIGHT_CHANGED;      /* we just shortened the "dir" subtree */
      
    case  AVL_IS_TREE  :
      decrease = avl_delete( avlDesc,
			     &( (*rootp) -> data ),
			     &( (*rootp) -> subtree[ RIGHT ] ),
			     avl_min				);
    } /* switch */
  } /* else */
  
  (*rootp) -> bal -= decrease;       /* update balance factor */
  
      /**********************************************************************
       * Rebalance if necessary -- the height of current tree changes if one
       * of two things happens: (1) a rotation was performed which changed
       * the height of the subtree (2) the subtree height decreased and now
       * matches the height of its other subtree (so the current tree now
       * has a zero balance when it previously did not).
       **********************************************************************/
  if ( decrease  &&  (*rootp) -> bal )	/* return 1 if height      */
    return  balance( rootp );		/* changed due to rotation */
  
  else if ( decrease  && !(*rootp) -> bal )	/* or if balance is 0 from    */
    return  HEIGHT_CHANGED;			/* height decrease of subtree */
  
  else
    return  HEIGHT_UNCHANGED;
  
}/* avl_delete */



/**
*	Routines which Recursively Traverse an AVL TREE
*
* These routines may perform a particular action function upon each node
* encountered. In these cases, "action" has the following definition:
*
*   void action( data, order, node, level, bal )
*       void   *data
*       AvlVisit   order;
*       AvlNodeType    node;
*	short	bal;
*       int     level;
*
*         "data"    is a pointer to the data field of an AVL node
*         "order"   corresponds to whether this is the 1st, 2nd or 3rd time
*                   that this node has been visited.
*         "node"    indicates which children (if any) of the current node
*                   are null.
*         "level"   is the current level (or depth) in the tree of the
*                   curent node.
*         "bal"     is the balance factor of the current node.
**/


/************************************************************************
*	Walk an AVL tree, performing a given function at each node
************************************************************************/


/*
* avl_walk -- traverse the given tree performing "action"
*            upon each data item encountered.
*
*/
static     void
avl_walk( 
    AVLtree        tree,
    void           (*action)( void * data, AvlVisit order, AvlNodeType node,
			      int level, short bal, void * closure),
    void * 	   closure,
    AvlSiblingOrder  sibling_order,
    int            level
    )
{
  DIRECTION  dir1 = (sibling_order == AVL_LEFT_TO_RIGHT) ? LEFT : RIGHT,
    dir2 = OPPOSITE( dir1 );
  AvlNodeType       node = node_type( tree );
  
  if ( (tree != NULL_TREE)  &&  (action != NULL) )  {
    (*action)( tree -> data, AVL_PREORDER, node, level, tree -> bal, closure );
    
    if ( tree -> subtree[ dir1 ]  !=  NULL_TREE )
      avl_walk( tree -> subtree[ dir1 ], action, closure, sibling_order, level+1 );
    
    (*action)( tree -> data, AVL_INORDER, node, level, tree -> bal, closure );
    
    if ( tree -> subtree[ dir2 ]  !=  NULL_TREE )
      avl_walk( tree -> subtree[ dir2 ], action, closure,
		sibling_order, level+1 );
    
    (*action)( tree -> data, AVL_POSTORDER, node, level, tree -> bal, closure );
  }/* if non-empty tree */
  
}/* avl_walk */



/************************************************************************
*	Walk an AVL tree, de-allocating space for each node
*       and performing a given function at each node
*       (such as de-allocating the user-defined data item).
************************************************************************/


/*
* avl_free() -- free up space for all nodes in a given tree
*              performing "action" upon each data item encountered.
*
*	(only perform "action" if it is a non-null function) 
*/

static     void
avl_free( 
    AVLdescriptor  *avlDesc,
    AVLtree        *rootp,
    void           (*action)( void * data, AvlVisit order, void * closure),
    void *	   closure,
    AvlSiblingOrder  sibling_order,
    int            level
    )
{
  DIRECTION  dir1 = (sibling_order == AVL_LEFT_TO_RIGHT) ? LEFT : RIGHT,
    dir2 = OPPOSITE( dir1 );
  AvlNodeType       node = node_type( *rootp );
  
  if ( *rootp != NULL_TREE )  {
    
    if ( action != NULL_ACTION )
      (*action)( (*rootp) -> data, AVL_PREORDER, closure );
    
    if ( (*rootp) -> subtree[ dir1 ]  !=  NULL_TREE )
      avl_free( avlDesc, &( (*rootp) -> subtree[ dir1 ] ),
		action, closure, sibling_order, level+1 );
    
    if ( action != NULL_ACTION )
      (*action)( (*rootp) -> data, AVL_INORDER, closure );
    
    if ( (*rootp) -> subtree[ dir2 ]  !=  NULL_TREE )
      avl_free( avlDesc, &( (*rootp) -> subtree[ dir2 ] ),
		action, closure, sibling_order, level+1 );
    
    if ( action != NULL_ACTION )
      (*action)( (*rootp) -> data, AVL_POSTORDER, closure );
    
    free_node( avlDesc,  rootp );
  }/* if non-empty tree */
  
}/* avl_free */




/**********************************************************************
* 
*		C-interface (public functions) for avl trees 
*
*	These are the functions that are visible to the user of the
*	AVL Tree Library. Mostly they just return or modify a
*	particular attribute, or Call a private functions with the
*	given parameters.
*
*	Note that public routine names begin with "avl" whereas
*	private routine names that are called by public routines
*	begin with "avl_" (the underscore character is added).
*
*	Each public routine must convert (cast) any argument of the 
*	public type "AvlTree" to a pointer to on object of the 
*	private type "AVLdescriptor" before passing the actual 
*	AVL tree to any of the private routines. In this way, the
*	type "AvlTree" is implemented as an opaque type.
* 
*	An "AVLdescriptor" is merely a container for AVL-tree
*	objects which contains the pointer to the root of the 
*	tree and the various attributes of the tree.
*
*	The function types prototypes for the routines which follow
*	are declared in the include file "avl.h"
*
***********************************************************************/


/*
* AvlInit() -- get space for an AVL descriptor for the given tree
*              structure and initialize its fields.
*/
AvlTree
AvlInit(
    int    (*compar)( const void * data1, const void * data2, AvlNodeType nd),
    void * (*getMem)( size_t size, void * closure ),
    void   (*freeMem)( void * data, void * closure ),
    void * memClosure 
    )
{
    AVLdescriptor  *avl_desc;

    avl_desc = (AVLdescriptor *) avlMalloc( sizeof( AVLdescriptor ), NULL );
    
    if( getMem != NULL && freeMem != NULL )
      {
    	avl_desc->root = (AVLroot *) getMem( sizeof (AVLroot), memClosure );
	
	avl_desc->getMem     = getMem;
	avl_desc->freeMem    = freeMem;
	avl_desc->memClosure = memClosure;
      }
    else
      {
    	avl_desc->root = (AVLroot *) avlMalloc( sizeof (AVLroot), NULL );

	avl_desc->getMem     = avlMalloc;
	avl_desc->freeMem    = avlFree;
	avl_desc->memClosure = NULL;
      }
    
    avl_desc->compar	= compar;
    
    avl_desc->root->root	= NULL_TREE;
    avl_desc->root->count	= 0;
    avl_desc->root->versionId = AVL_VERSION;
  
    return  (AvlTree) avl_desc;
}/* avlinit */

/*
 * AvlAttach - Attach to an exsisting root
 */

AvlTree
AvlAttach(
    void * avlRoot,
    int    (*compar)( const void * data1, const void * data2, AvlNodeType nd),
    void * (*getMem)( size_t size, void * closure ),
    void   (*freeMem)( void * data, void * closure ),
    void * memClosure
    )
{
  AVLroot * 		root = (AVLroot *) avlRoot;
  AVLdescriptor *  	avl_desc;
  
  avl_desc = (AVLdescriptor *) avlMalloc( sizeof( AVLdescriptor ), NULL );

  if( avl_desc == NULL )
    {
      SET_ERROR( C_EOSERROR );
      return( NULL );
    }
  
  if( root->versionId != AVL_VERSION )
    {
      SET_ERROR( C_EBADPARAM );
      return( NULL );
    }

  avl_desc->root = root;
  
  if( getMem != NULL && freeMem != NULL )
    {	
      avl_desc->getMem     = getMem;
      avl_desc->freeMem    = freeMem;
      avl_desc->memClosure = memClosure;
    }
  else
    {
      avl_desc->getMem     = avlMalloc;
      avl_desc->freeMem    = avlFree;
      avl_desc->memClosure = NULL;
    }
  
  avl_desc->compar	= compar;
  
  return( avl_desc );
  
}/* AvlAttach */

void *
AvlDetach( AvlTree * avlTree )
{
  AVLdescriptor *  avl_desc = (AVLdescriptor *) avlTree;
  
  AVLroot * root = avl_desc->root;

  avlFree( avl_desc, NULL );

  avlTree = NULL;
  
  return( root );
}
 
void *
AvlGetRoot( AvlTree  avlTree )
{
  AVLdescriptor *  avl_desc = (AVLdescriptor *) avlTree;

  return( avl_desc->root );
}

/*
* avldispose() -- free up all space associated with the given tree structure.
*/
void
AvlDispose( 
    AvlTree *        treeptr,
    void             (*action)( void * data, AvlVisit order, void * closure ),
    AvlSiblingOrder  sibling_order,
    void *	     closure
    )
{
  AVLdescriptor * avl_desc = (AVLdescriptor *) *treeptr;
  
  avl_free( avl_desc,
	    &(avl_desc->root->root),
	    action,
	    closure,
	    sibling_order,
	    1 );

  avlFree( avl_desc, NULL );
  
  *treeptr = (AvlTree) NULL;
  
}/* avldispose */



/*
* avlwalk() -- traverse the given tree structure and perform the
*              given action on each data item in the tree.
*/
void
AvlWalk( 
    AvlTree       tree,
    void          (*action)( void * data, AvlVisit order, AvlNodeType node,
			     int level, short bal, void * closure),
    AvlSiblingOrder  sibling_order,
    void * 	   closure
    )
{
  AVLdescriptor * avl_desc = (AVLdescriptor *) tree;
  
  avl_walk( avl_desc->root->root, action, closure, sibling_order, 1 );
  
}/* avlwalk */
  
   
/*
* avlcount () --  return the number of nodes in the given tree
*/
unsigned long
AvlCount( AvlTree tree )
{
  AVLdescriptor * avl_desc = (AVLdescriptor *) tree;
  
  return  avl_desc->root->count;
}/* avlcount */

 

/*
* AvlAdd() -- insert the given item into the tree structure
*/
void *
AvlAdd( 
    AvlTree  tree,
    void      *data
    )
{
    AVLdescriptor  *avl_desc = (AVLdescriptor *) tree;
    void *	   avlData = data;

    avlData = data;
    
    avl_insert( avl_desc, &avlData, &(avl_desc->root->root), avl_desc->compar );
    if ( avlData == NULL )    ++(avl_desc->root->count);

    return  avlData;
}/* avlins */



/*
* AvlDel() -- delete the given item from the given tree structure
*/
void  *
AvlDel( 
    AvlTree  tree,
    void      *data
    )
{
    AVLdescriptor  *avl_desc = (AVLdescriptor *) tree;
    void *	   avlData = data;

    avl_delete( avl_desc, &avlData, &(avl_desc->root->root), avl_desc->compar );
    if ( avlData != NULL )     --(avl_desc->root->count);
  
    return  avlData;
}/* avldel */



/*
* AvlFind() -- find the given item in the given tree structure
*              and return its address (NULL if not found).
*/
void *
AvlFind( 
    AvlTree       tree,
    const void *  data
    )
{
    AVLdescriptor  *avl_desc = (AVLdescriptor *) tree;
  
    return  avl_find( data, avl_desc->root->root, avl_desc->compar );
}/* avlfind */

  
/*
* AvlDelMin() -- delete the minimal item from the given tree structure
*/
void *
AvlDelMin( AvlTree  tree )
{
    AVLdescriptor  *avl_desc = (AVLdescriptor *) tree;
    void  *data;
  

    avl_delete( avl_desc, &data, &(avl_desc->root->root), avl_min );
    if ( data != NULL )     --(avl_desc->root->count);
  
    return  data;
}/* avldelmin */



/*
* AvlFindMin() -- find the minimal item in the given tree structure
*              and return its address (NULL if not found).
*/
void *
AvlFindMin( AvlTree  tree )
{
    AVLdescriptor  *avl_desc = (AVLdescriptor *) tree;
  
    return  avl_find( NULL, avl_desc->root->root, avl_min );
}/* avlfindmin */

  

/*
* AvlDelMax() -- delete the maximal item from the given tree structure
*/
void *
AvlDelMax( AvlTree  tree )
{
    AVLdescriptor  *avl_desc = (AVLdescriptor *) tree;
    void  *data;
  
    avl_delete( avl_desc, &data, &(avl_desc->root->root), avl_max );
    if ( data != NULL )     --(avl_desc->root->count);
  
    return  data;
}/* avldelmax */

  

/*
* AvlFindMax() -- find the maximal item in the given tree structure
*              and return its address (NULL if not found).
*/
void *
AvlFindMax ( AvlTree  tree )
{
    AVLdescriptor  *avl_desc = (AVLdescriptor *) tree;
  
    return  avl_find( NULL, avl_desc->root->root, avl_max );
}/* avlfindmax */







