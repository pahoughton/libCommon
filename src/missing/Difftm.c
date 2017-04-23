/* 1991-10-14 (cc) <paul4hough@gmail.com>
 * compares tm structs, returns the diff in seconds
 */

#include "datetime.h"

time_t Difftm(struct tm *t1, struct tm *t2)
{
  return( mktime(t1) - mktime(t2) );
}
