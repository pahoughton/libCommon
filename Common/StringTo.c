/* 1994-08-04 (cc) Paul Houghton <paul4hough@gmail.com>
 */
/* 1994-06-16 (cc) paul4hough@gmail.com

   Convert a number string into its apropriate binary value.
   If base is 0, the string will define its base as in C. A
   leading 0 implies octal and 0x implies hexadecimal.
*/

#include "_Common.h"
#include <ctype.h>
#include <math.h>

#define MSTRING_TO_TYPE( _t_, _T_ )					\
_t_									\
StringTo##_T_(								\
    const char * string,						\
    int		 base,							\
    int          len							\
    )									\
{									\
									\
  int pos = 0;								\
  _t_ value = 0;							\
  int neg = string[pos] == '-' ? ++pos : 0;				\
  int prebase = base ? base : 10;					\
									\
  for( ; ! IS_BASE_DIGIT( string[pos], prebase )			\
         && ( len != 0 ? pos < len : string[pos] != 0 )			\
	 ; pos++ );							\
									\
  if( base == 0 )							\
    {									\
      if( string[pos] == '0' )						\
	{								\
	  ++ pos;							\
	  if( tolower( string[pos] ) == 'x')				\
	    {								\
	      base = 16;						\
	      ++ pos;							\
	    }								\
	  else								\
	    {								\
	      base = 8;							\
	    }								\
	}								\
      else								\
	{								\
	  base = 10;							\
	}								\
    }									\
									\
  for( ; (len != 0 && pos < len ) || (len == 0 && string[pos] != 0);	\
       pos++ )								\
    {									\
      if( IS_BASE_DIGIT( string[pos], base ) )				\
	{								\
	  value *= base;						\
	  value += CHAR_TO_INT( string[pos] );				\
	}								\
    }									\
  if( neg ) value *= -1;						\
									\
  return( value );							\
}

MSTRING_TO_TYPE( int, Int  );
MSTRING_TO_TYPE( long, Long );
MSTRING_TO_TYPE( short, Short );
MSTRING_TO_TYPE( unsigned int, UInt  );
MSTRING_TO_TYPE( unsigned long, ULong );
MSTRING_TO_TYPE( unsigned short, UShort );



double
StringToDouble(
  const char * string,
  int          len )
{

  int    pos = 0;
  double value = 0;
  int    neg = string[pos] == '-' ? ++pos : 0;
  int	 fract = -1;

  for( ; ! IS_BASE_DIGIT( string[pos], 10 )
         && ( len != 0 ? pos < len : string[pos] != 0 )
	 ; pos++ );

  for( ; (len != 0 && pos < len )
	 || (len == 0 && string[pos] != 0);
       pos++ )
    {
      if( fract == -1 && string[pos] == '.' )
	{
	  fract = 0;
	}
      else
	{
	  if( IS_BASE_DIGIT( string[pos], 10 ) )
	    {
	      if( fract > -1 )
		{
		  fract++;
		}
	      value *= 10;
	      value += CHAR_TO_INT( string[pos] );
	    }
	  else
	    {
	      break;
	    }
	}
    }

  if( fract > 0 )
    {
      value = value * pow( (double)10, (double)(-1 * fract) );
    }

  if( neg ) value *= -1;

  return( value );
}
