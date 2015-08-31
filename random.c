/*
** how to use random
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
t_rand(void)
{
    for(int i=0; i<10; i++){
        int a = rand();
        printf("%d \n", a);
    }
}

void
t_seed(void)
{
    srand(9999);
    for(int i=0; i<10; i++){
        int a = rand();
        printf("%d \n", a);
    }
}

int
main( void )
{
    t_seed();
	return 1;
}
