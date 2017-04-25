#ifndef _missing_missing_h_
#define _missing_missing_h_
/* 1993-09-03 (cc) paul4hough@gmail.com
 */

#include <missing/error.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MISSING_LIB_VERSION	    0x03010100
#define MISSING_LIB_VERSION_STR	    "3.1.1"

/* Boolean type and values */

#if !defined( BOOL )
#define BOOL	int
#endif

#if !defined( TRUE )
#define TRUE 1
#endif

#if !defined( FALSE )
#define FALSE 0
#endif

#if !defined( ON )
#define ON TRUE
#define OFF FALSE
#endif

#if !defined( NO )
#define NO  	FALSE
#define YES 	TRUE
#endif

#if !defined( CHAR_ALL_BITS )

#define Bit( _b_ ) ( 1 << _b_ )

#define CHAR_BITS   CHAR_BIT
#define SHORT_BITS  ( sizeof(short) * CHAR_BITS )
#define LONG_BITS   ( sizeof(long) * CHAR_BITS )
#define INT_BITS    ( sizeof(int) * CHAR_BITS )

#define CHAR_ALL_BITS	((unsigned char)(~0))  /* 0xff */
#define SHORT_ALL_BITS	((unsigned short)(~0)) /* 0xffff */
#define LONG_ALL_BITS	((unsigned long)(~0L)) /* 0xffffffff */
#define INT_ALL_BITS	((unsigned int)(~0))   /* 0xffff | 0xffffffff */

#endif
#if !defined( TIMET_MAX )
#define TIMET_MAX   LONG_MAX
#define TIMET_MIN   LONG_MIN
#endif


/**************************************************************
 * S T R I N G   P r o c e s s i n g
 **************************************************************/


#define CHAR_TO_INT( _d_ ) \
( ( _d_ <= '9' ) ? _d_ - '0' : ( 10 + ( (_d_ | 0x20) - 'a' ) ))

#define IS_BASE_DIGIT( _d_, _b_ ) \
(CHAR_TO_INT(_d_) >= 0 && CHAR_TO_INT(_d_) < _b_ )

#define SAFE_STRCPY( _dest_, _src_, _size_ );    \
strncpy( _dest_, _src_, _size_); _dest_[_size_ - 1] = 0;


extern const unsigned char EtoA[];
extern const unsigned char AtoE[];

#define E2A( _c_ ) (EtoA[((unsigned char)(_c_))])
#define A2E( _c_ ) (AtoE[((unsigned char)(_c_))])

int   	    	StringToInt( const char * str, int base, int len );
unsigned int   	StringToUInt( const char * str, int base, int len );
short	    	StringToShort( const char * str, int base, int len );
unsigned short	StringToUShort( const char * str, int base, int len );
long  	    	StringToLong( const char * str, int base, int len );
unsigned long   StringToULong( const char * str, int base, int len );
double 	    	StringToDouble( const char * str, int bash, int len );

char * CenterLine( char * dest, const char * src, int width );
void StripSpaces( char * buffer );

void EbcdicToAscii( unsigned char * buf, int len );
void AsciiToEbcdic( unsigned char * buf, int len );

#if defined( MISSING_CSTUFF )
char * strlwr( char * str );
char * strupr( char * str );
char * strdup( const char *);
const char * basename( const char * path );
#endif

/**************************************************************
 * Bit manipulation - (see CommonConfig.h for values)
 *
 * #define Bit( bitNumber )
 *
 * #define CHAR_BITS
 * #define SHORT_BITS
 * #define LONG_BITS
 * #define INT_BITS
 *
 * #define CHAR_ALL_BITS
 * #define SHORT_ALL_BITS
 * #define LONG_ALL_BITS
 * #define INT_ALL_BITS
 *
 **************************************************************/


/**************************************************************
 * M I S C
 **************************************************************/

const char *
TempFileName( const char * dir, const char * prefix );

Ret_Status
ForeachFile( const char *   name,
	     Ret_Status     (*fileProc)( const char * name,
					 void * closure ),
	     BOOL	    recurs,
	     void *	    closure );

BOOL
CanExecute( const char * fileName );

char *
FindPath( const char * fileName, const char * path );

#if defined( COMMON_HAVE_GROUPS )
BOOL
MemberOfGroup( gid_t grp );
#endif

#if defined( COMMON_HAVE_MODE_T )
const char *
FileModeString( mode_t	mode, char * modeString );
#endif

#define DWORD_ALIGN( _addr_ ) \
  ( ((_addr_ % 4) == 0) ? _addr_ :  ( _addr_  + ( 4 - ( _addr_ % 4 ) ) ) )


#ifdef __cplusplus
}
#endif

#endif /* ! _missing_missing_h_ */
