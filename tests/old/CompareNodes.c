/* 1994-07-15 (cc) Dora Potluri
 */

#include <stdio.h>
#include <Common.h>


#include <AvlTest.h>

int CompareNodes(
    void * 	dataOne,
    void * 	dataTwo,
    AvlNodeType nd )
{


  return ( *( (int* ) dataOne) - *((int *) dataTwo) );
}
