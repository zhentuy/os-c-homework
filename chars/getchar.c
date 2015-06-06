/*
** This program test how to use c lib getchar
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main( void )
{

	char ch;

	while( (ch = getchar())  && ch != '\n' )
		printf( "got char %c\n", ch );
        puts(&ch);

	return EXIT_SUCCESS;
}
