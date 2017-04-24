#ifndef _verify_h_
#define _verify_h_
/* 2017-04-23 (cc) <paul4hough@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>

#define VVTRUE( _truth_ )					\
  {								\
    if( ! (_truth_) ) {						\
      printf("fail:%s:%d:%s\n",__FILE__,__LINE__,#_truth_);	\
      exit(1);							\
    }								\
  }

#if defined( __cplusplus )
extern "C" {
#endif



#if defined( __cplusplus )
};
#endif

#endif /* ! def _verify_h_ */
