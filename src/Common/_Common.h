
extern int errno;

#define SUCCEED 0
#define ERROR 1

#define SET_ERROR( _error_ )						     \
									     \
  ErrFile = __FILE__;							     \
  ErrLine = __LINE__;							     \
  if( (_error_) == E_OSERROR ) OsErr = errno;				     \
  Errno = _error_;							     \
  
#include <_CommonProto.h>
    
