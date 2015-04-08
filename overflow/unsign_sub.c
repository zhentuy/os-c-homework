/*
** This program show what should notice when use unsigned int
*!!  modern compaile auto deal overflow , my test failing !!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * cause strlen return an unsigned int, there sub result also unsigned int 
 * there always s is long than t
*/
int 
strlonger(char *s, char *t)
{
    unsigned lens = strlen(s);
    unsigned lent = strlen(t);
    return lens - lent;
}

int
main( void )
{
	char *a = "0123";
	char *b = "0123456";
    printf( "a is : %s\n", a );
    printf( "b is : %s\n", b );
    int r1 = strlonger(a, b);
    printf( "length compare(a, b) result is: %d\n", r1 );
    int r2 = strlonger(b, a);
    printf( "length compare(b, a) result is: %d\n", r2 );
	return EXIT_SUCCESS;
}
