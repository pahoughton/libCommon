/* 1994-08-04 (cc) Paul Houghton <paul4hough@gmail.com>
 */
/****************************************************************
 *
 * Semaphores for Locking/Unlocking
 *
 ****************************************************************/

int
AvlLockTree(
  AvlTree avlTree ,
  int	  semId )
{
  AVLdescriptor *  avlDesc = (AVLdescriptor *) avlTree;
  struct sembuf	    semOps[2];

  semOps[0].sem_num = 0;
  semOps[0].sem_op = 0;
  semOps[0].sem_flg = 0;

  semOps[1].sem_num = 0;
  semOps[1].sem_op = 1;
  semOps[1].sem_flg = 0;

  if ( semop( semId, semOps, 2 ) == -1 )
    {
#ifdef LOCK_DEBUG      
      printf("Error in AvlLockTree:%d \n", errno );
#endif      
      return( -1 );
    }
  
  avlDesc->root->numberOfUsers++;

#ifdef LOCK_DEBUG  
  printf("Debug:AvlLockTree() numberOfUsers:%d \n", avlDesc->root->numberOfUsers );
#endif
  
  return( 0 );
}

int
AvlUnlockTree(
  AvlTree avlTree,
  int     semId )
{
  AVLdescriptor *  avlDesc = (AVLdescriptor *) avlTree;
  struct sembuf    semOps[2];

  avlDesc->root->numberOfUsers++;
  
  semOps[0].sem_num = 0;
  semOps[0].sem_op = -1;
  semOps[0].sem_flg = 0;

  if ( semop( semId, semOps, 1 ) == -1 )
    {
#ifdef LOCK_DEBUG      
      printf("Error in AvlUnlockTree:%d \n", errno );
#endif      
      return( -1 );
    }
#ifdef LOCK_DEBUG  
  printf("Debug:AvlLockTree() numberOfUsers:%d \n", avlDesc->root->numberOfUsers );
#endif
  
  return(0);
}    

int
AvlWaitForUnlock(
  AvlTree avlTree ,
  int 	  semId )
{
  AVLdescriptor *  avlDesc = (AVLdescriptor *) avlTree;
  struct sembuf	 semOps[2];

  semOps[0].sem_num = 0;
  semOps[0].sem_op = 0;
  semOps[0].sem_flg = 0;

  if ( semop( semId, semOps, 1 ) == -1 )
    {
#ifdef LOCK_DEBUG      
      printf("Error in AvlWaitForUnlock:%d \n", errno );
#endif      
      return( -1 );
    }
  return(0 );
}

int
AvlGetNumberOfUsers(
  AvlTree avlTree )
{
  AVLdescriptor *  avlDesc = (AVLdescriptor *) avlTree;

#ifdef LOCK_DEBUG  
  printf("Debug:AvlLockTree() numberOfUsers:%d \n", avlDesc->root->numberOfUsers );
#endif
  
  return( avlDesc->root->numberOfUsers );
}
