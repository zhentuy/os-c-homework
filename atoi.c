/*
** how to use random
*/

#include <stdio.h>
#include <stdlib.h>

char * sia = "2578abcg haha";
char * sib = "0x2578abcg haha";

void
t_atoi(void)
{
    printf("%d \n", atoi(sia));
}

void
t_strtol(void)
{
    char * brk;
    int en = strtol(sia, &brk, 6);
    printf("char turned %d \n", en);
    printf("leaved: ' %s ' \n", brk);

    int em = strtol(sia, &brk, 8);
    printf("char turned %d \n", em);
    printf("leaved: ' %s ' \n", brk);

    int eo = strtol(sia, &brk, 16);
    printf("char turned %d \n", eo);
    printf("leaved: ' %s ' \n", brk);

    /* 0x format only accepted by base 0 */
    int ep = strtol(sib, &brk, 0);
    printf("char turned %d \n", ep);
    printf("leaved: ' %s ' \n", brk);
}

int
main( void )
{
    t_strtol();
	return 1;
}
