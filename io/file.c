/*
** do file
*/

#include <stdio.h>
#include <stdlib.h>

void
t_open(void)
{
    char *fname = "/tmp/cstream.test";
    printf("** open file  %s ** \n", fname);
    FILE *input;
    input = fopen(fname, "w");
    if( input == NULL ){
        perror(fname);
        exit(0);
    }
    fputs("1234 5678 \n", input);
    fclose(input);
}

int
main( void )
{
    t_open();
	return 1;
}
