/* 1994-11-11 (cc) Dora Potluri
 */
static const char * RcsId =
"$Id$";

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#define _XOPEN_SOURCE
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/mode.h>

#define SEM_ACCESS  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH

int
InitLocking(
  const char * fileName ,
  int	       accessFlag,
  const char  keyID )
{
  int	    semId;

  key_t semKey;

  if ( ( semKey = ftok( fileName, keyID ) ) == (key_t)-1 )
    {
      printf("Failed to generate a key Error:%d \n" , errno );
      return(-1);
    }

  /*
    Algorithm:
    If the Memory mapped file is being created then,
    Try to create a new semaphore, if one already exists remove the old one.
    then create the new semaphore.

    For all other purposes of mapping like Read-Write Read only
    get the existing semaphore and operate on that.
    */

  if ( accessFlag & O_CREAT &&
       ( semId = semget( semKey, 1,IPC_CREAT | IPC_EXCL | SEM_ACCESS ) ) == -1 )
    {
      if ( errno == EEXIST )
	{
	  /*
	    Get the old Semaphore
	    */

	  if ( ( semId = semget( semKey, 1, IPC_CREAT | SEM_ACCESS ) ) == -1 )
	    {
	      printf(" Failed to get the old Sem Error:%d\n", errno );
	      return( -1 );
	    }

	  /*
	    Remove the old semaphore
	    */

	  if ( semctl( semId, 1, IPC_RMID, NULL ) != 0 )
	    {
	      printf("Failed to remove the semapore Error:%d \n", errno );
	      return( -1 );
	    }

	  /*
	    Now get the new one
	    */

	  if ( ( semId = semget( semKey, 1,IPC_CREAT | IPC_EXCL
						   | SEM_ACCESS ) ) == -1 )
	    {
	      printf("Failed to create a new Sem Error:%d \n", errno );
	      return(-1);
	    }

	  return( semId );
	}
      return( -1 );
    }
  else
    {
      if ( ( semId = semget( semKey, 1, IPC_CREAT | SEM_ACCESS ) ) == -1 )
	{
	  printf(" Failed to get Exisiting Sem Error:%d\n", errno );
	  return( -1 );
	}
    }

  return( semId );
}
