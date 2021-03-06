/* 1994-08-04 (cc) Paul Houghton <paul4hough@gmail.com>
 */
/**
* avl_typs.h -- declaration of private types used for avl trees
*
* Created 03/01/89 by Brad Appleton
*
* ^{Mods:* }
* 
* Fri Jul 14 13:55:58 1989, Rev 1.0, brad(0165)
* 
**/


  /* definition of a NULL action and a NULL tree */
#define NULL_ACTION    ( ( void (*)( void *, AvlVisit, void *) ) 0 )
#define NULL_TREE      ( (AVLtree)     NULL )
  
  
        /* MIN and MAX macros (used for rebalancing) */
#define  MIN(a,b)    ( (a) < (b) ? (a) : (b) )
#define  MAX(a,b)    ( (a) > (b) ? (a) : (b) )
  
  
       /* Directional Definitions */
typedef  short  DIRECTION;
#define  LEFT           ((DIRECTION) 0)
#define  RIGHT          ((DIRECTION) 1)
#define  OPPOSITE(x)	((DIRECTION) ( 1 - (x) ))
  

       /* return codes used by avl_insert(), avl_delete(), and balance() */
#define  HEIGHT_UNCHANGED	0
#define  HEIGHT_CHANGED		1


       /* Balance Definitions */
#define  LEFT_HEAVY            -1
#define  BALANCED               0
#define  RIGHT_HEAVY            1
#define  LEFT_IMBALANCE(nd)    ( (nd)->bal < LEFT_HEAVY  )
#define  RIGHT_IMBALANCE(nd)   ( (nd)->bal > RIGHT_HEAVY )
  
  
  /* structure for a node in an AVL tree */
typedef struct avl_node {
    void	*data;            /* pointer to data */
    short	bal;             /* balance factor */
    struct avl_node  *subtree[2];      /* LEFT and RIGHT subtrees */
} AVLnode, *AVLtree;


typedef struct
{
  unsigned long	versionId;
  AVLtree	root;	/* pointer to the root node of the tree */
  unsigned long count;	/* number of nodes in the tree */
  void *	treeData;
} AVLroot;

  /* structure which holds information about an AVL tree */
typedef struct avl_descriptor {
  int		(*compar)(const void * data1, const void * data2, AvlNodeType nd);
  void * 	(*getMem)( size_t size, void * closure );
  void  	(*freeMem)( void * data, void * closure );
  void *	memClosure;
  AVLroot *	root;           /* pointer to the root node of the tree */
} AVLdescriptor;




