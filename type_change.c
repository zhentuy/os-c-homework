/*
** view type change
*/

#include <stdio.h>
#include <stdlib.h>

void
s_us(void)
{
    short i = -12345;
    printf("before changing: i=%i \n", i );
    unsigned short ui = (unsigned short) i;
    printf("after changing: ui=%u \n", ui);
    unsigned short absi = abs(i);
    printf("abs : i=%u \n", absi);
}

int
main( void )
{
    s_us();
	return 1;
}
