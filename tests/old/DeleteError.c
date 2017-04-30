/* 1994-07-15 (cc) Dora Potluri
 */

#include <stdio.h>

#include <Common.h>


#include <AvlTest.h>


void DeleteError(
    void 	*data,
    AvlVisit	order,
    void 	*closure )
{
  int *	value = (int *) data;

  printf("Still In the tree %d \n", *value);
}
