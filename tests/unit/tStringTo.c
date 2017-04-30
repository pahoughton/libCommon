/* 2017-04-23 (cc) <paul4hough@gmail.com>
 */

#include "proto.h"

#include <Common/Common.h>
#include <Common/verify.h>

struct IntTestVal
{
  const char *      str;
  unsigned short    base;
  size_t    	    len;
  int	    	    good;
  int	    	    value;
};

static struct IntTestVal IntTestValues[] =
  {
    { " 5 ",  	    0,  2, TRUE,        5 },
    { " 010 15",    0,  4, TRUE,      010 },
    { "-1500123",   0,  5, TRUE,    -1500 },
    { "0x2399",     0,  4, TRUE,     0x23 },
    { "-0xabcd",    0,  5, TRUE,    -0xab },
    { "  11099",    0,  5, TRUE,      110 },
    { "       ",    0,  5, TRUE,        0 },

    { " 5 ",  	   10,  2, TRUE,        5 },
    { " 010 15",   10,  4, TRUE,       10 },
    { "-1500123",  16,  5, TRUE,    -5376 },
    { "0x2399",    16,  4, TRUE,     0x23 },
    { "-0xabcd",   16,  5, TRUE,    -0xab },
    { "  11099",    8,  5, TRUE,     0110 },
    { "       ",    8,  5, TRUE,        0 },

    {0, 0, 0, 0L}
  };

struct LongTestVal
{
  const char *      str;
  unsigned short    base;
  size_t    	    len;
  int	    	    good;
  long	    	    value;
};

static struct LongTestVal LongTestValues[] =
  {
    { " 5 ",  	    0,  2, TRUE,        5L },
    { " 010 15",    0,  4, TRUE,      010L },
    { "-1500123",   0,  5, TRUE,    -1500L },
    { "0x2399",     0,  4, TRUE,     0x23L },
    { "-0xabcd",    0,  5, TRUE,    -0xabL },
    { "  11099",    0,  5, TRUE,      110L },
    { "       ",    0,  5, TRUE,        0L },

    { " 5 ",  	   10,  2, TRUE,        5L },
    { " 010 15",   10,  4, TRUE,       10L },
    { "-1500123",  16,  5, TRUE,    -5376L },
    { "0x2399",    16,  4, TRUE,     0x23L },
    { "-0xabcd",   16,  5, TRUE,    -0xabL },
    { "  11099",    8,  5, TRUE,     0110L },
    { "       ",    8,  5, TRUE,        0L },

    { "0x0fffffff",  0,  0, TRUE,	0x0fffffffL },
    { "-99999999",   0,  0, TRUE,	-99999999L },
    { "99999999",    0,  0, TRUE,	 99999999L },

    {0, 0, 0, 0L}
  };

struct ShortTestVal
{
  const char *      str;
  unsigned short    base;
  size_t    	    len;
  int	    	    good;
  short	    	    value;
};

static struct ShortTestVal ShortTestValues[] =
  {
    { " 5 ",  	    0,  2, TRUE,        5 },
    { " 010 15",    0,  4, TRUE,      010 },
    { "-1500123",   0,  5, TRUE,    -1500 },
    { "0x2399",     0,  4, TRUE,     0x23 },
    { "-0xabcd",    0,  5, TRUE,    -0xab },
    { "  11099",    0,  5, TRUE,      110 },
    { "       ",    0,  5, TRUE,        0 },

    {0, 0, 0, 0L}
  };

struct UIntTestVal
{
  const char *      str;
  unsigned short    base;
  size_t    	    len;
  int	    	    good;
  unsigned int 	    value;
};

static struct UIntTestVal UIntTestValues[] =
  {
    { " 5 ",  	    0,  2, TRUE,          5 },
    { " 010 15",    0,  4, TRUE,        010 },
    { "0x2399",     0,  4, TRUE,       0x23 },
    { "  11099",    0,  5, TRUE,        110 },
    { "       ",    0,  5, TRUE,          0 },

    { " 5 ",  	   10,  2, TRUE,          5 },
    { " 010 15",   10,  4, TRUE,         10 },
    { "0x2399",    16,  4, TRUE,       0x23 },
    { "  11099",    8,  5, TRUE,       0110 },
    { "       ",    8,  5, TRUE,          0 },

    { "3123123123", 10, 0, TRUE, 3123123123U },
    {0, 0, 0, 0L}
  };

struct ULongTestVal
{
  const char *      str;
  unsigned short    base;
  size_t    	    len;
  int	    	    good;
  unsigned long	    value;
};

static struct ULongTestVal ULongTestValues[] =
  {
    { " 5 ",  	    0,  2, TRUE,        5UL },
    { " 010 15",    0,  4, TRUE,      010UL },
    { "0x2399",     0,  4, TRUE,     0x23UL },
    { "  11099",    0,  5, TRUE,      110UL },
    { "       ",    0,  5, TRUE,        0UL },

    { " 5 ",  	   10,  2, TRUE,        5UL },
    { " 010 15",   10,  4, TRUE,       10UL },
    { "0x2399",    16,  4, TRUE,     0x23UL },
    { "  11099",    8,  5, TRUE,     0110UL },
    { "       ",    8,  5, TRUE,        0UL },

    { "0x0fffffff",  0,  0, TRUE,	0x0fffffffUL },
    { "99999999",    0,  0, TRUE,	 99999999UL },

    {0, 0, 0, 0L}
  };

struct UShortTestVal
{
  const char *      str;
  unsigned short    base;
  size_t    	    len;
  int	    	    good;
  unsigned short    value;
};

static struct UShortTestVal UShortTestValues[] =
  {
    { " 5 ",  	    0,  2, TRUE,        5 },
    { " 010 15",    0,  4, TRUE,      010 },
    { "0x2399",     0,  4, TRUE,     0x23 },
    { "  11099",    0,  5, TRUE,      110 },
    { "       ",    0,  5, TRUE,        0 },

    {0, 0, 0, 0L}
  };

struct DoubleTestVal
{
  const char *      str;
  size_t    	    len;
  double    	    value;
};

static struct DoubleTestVal DoubleTestValues[] =
  {
    { " 5 ",  	    2,        5L },
    { " 010 15",    4,       10L },
    { "-1500123",   5,    -1500L },
    { "  11099",    5,      110L },
    { "       ",    5,        0L },

    { " 5 ",  	    2,        5L },
    { " 010 15",    4,       10L },
    { "-1500123",   0, -1500123L },

    { "-99999999",  0,	-99999999L },
    { "99999999",   0,	 99999999L },

    { " 5.245",     0,       5.245 },
    { "-15.44",     0,     -15.44 },
    { " 010.11",    0,       10.11 },

    {0, 0, 0 }
  };


int
tStringTo(void)
{
#define myDEBUG(_x_)

#if !defined( myDEBUG )
#define myDEBUG( _dtype_ )					\
  printf("StringTo" #_dtype_ ":%s:%d:%lu:%lld:%lld\n",		\
	 _dtype_##TestValues[t].str,				\
	 _dtype_##TestValues[t].base,				\
	 _dtype_##TestValues[t].len,				\
	 (long long)_dtype_##TestValues[t].value,			\
	 (long long)StringTo##_dtype_( _dtype_##TestValues[t].str,	\
			    _dtype_##TestValues[t].base,	\
			    _dtype_##TestValues[t].len ) )
#endif

#define VSTRING_TO( _typ_ )					\
  {								\
    for( size_t t = 0; _typ_##TestValues[t].str; t++ )		\
      {								\
        myDEBUG( _typ_ );					\
	VVTRUE( StringTo##_typ_( _typ_##TestValues[t].str,	\
				 _typ_##TestValues[t].base,	\
				 _typ_##TestValues[t].len )	\
		== _typ_##TestValues[t].value );		\
      }								\
  }

  VSTRING_TO( Int );
  VSTRING_TO( Long );
  VSTRING_TO( Short );
  VSTRING_TO( UInt );
  VSTRING_TO( ULong );
  VSTRING_TO( UShort );

  /* Double */
  {
    for( size_t t = 0; DoubleTestValues[t].str; t++ )
      {

#if defined(DEBUG)
	printf("dbg:StringToDouble:%s:%lu:%lf:%lf\n",
	       DoubleTestValues[t].str,
	       DoubleTestValues[t].len,
	       DoubleTestValues[t].value,
	       StringToDouble( DoubleTestValues[t].str,
			       DoubleTestValues[t].len ) );
#endif
	VVTRUE( StringToDouble( DoubleTestValues[t].str,
				DoubleTestValues[t].len )
		== DoubleTestValues[t].value );
      }
  }

  return( TRUE );

}
