/**
*  avl.h -- public types and external declarations for avl trees
*
*  Created 03/01/89 by Brad Appleton
*
* ^{Mods:* }
* 
* Fri Jul 14 13:54:12 1989, Rev 1.0, brad(0165)
* 
**/
  
#ifndef AVL_H
#define AVL_H

#ifdef __cplusplus
extern "C" {
#endif
  
       /* definition of traversal type */
typedef  enum  { PREORDER, INORDER, POSTORDER }  VISIT;
  
  
       /* definition of sibling order type */
typedef  enum  { LEFT_TO_RIGHT, RIGHT_TO_LEFT }  SIBLING_ORDER;
  
  
       /* definition of node type */
typedef  enum  { IS_TREE, IS_LBRANCH, IS_RBRANCH, IS_LEAF, IS_NULL }  NODE;
  
  
       /* definition of opaque type for AVL trees */
typedef  void  *AVL_TREE;
  
  
  
     /* Constructor and Destructor functions for AVL trees:
     *          avlfree is a macro for avldispose in the fashion
     *          of free(). It assumes certain default values 
     *          (shown below) for the deallocation function and
     *          for the order in which children are traversed.
     */
AVL_TREE avlinit( int (*compar )(void *data1 ,void *data2 ,NODE nd ),
			 void *(*getMem )(size_t size ,void *closure ),
			 void (*freeMem )(void *data ,void *closure ),
			 void *memClosure );

void avldispose( AVL_TREE *treeptr ,
		 void (*action )(void *data ,void *closure ),
		 SIBLING_ORDER sibling_order,
		 void *closure );
void avlwalk( AVL_TREE tree ,
	      void (*action )(void *data ,VISIT order ,NODE node ,int level ,short bal ,void *closure ),
	      SIBLING_ORDER sibling_order ,
	      void *closure );
int avlcount( AVL_TREE tree );
void *avlins( AVL_TREE tree , void *data );
void *avldel( AVL_TREE tree , void *data );
void *avlfind( AVL_TREE tree , void *data );
void *avldelmin( AVL_TREE tree );
void *avlfindmin( AVL_TREE tree );
void *avldelmax( AVL_TREE tree );
void *avlfindmax( AVL_TREE tree );

#define avlfree(x)  avldispose _P( &(x), free, LEFT_TO_RIGHT )

#ifdef __cplusplus
};
#endif

#endif /* AVL_H */





