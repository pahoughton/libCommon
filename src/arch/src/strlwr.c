/*
 * convert a string to lower case
 */

#include <ctype.h>

char	*
strlwr(
	char	*str
	)
{

	char	*string = str;


while( *string != 0 )
	{
	if( isupper(*string) )
		{
		*string = tolower(*string);
		}
	string++;
	}
return(str);

}
