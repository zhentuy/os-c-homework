/*
** math lib
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double da = 2.2;
double db = 9.0;

void
t_pow(void)
{
    printf("pow result: %.2f \n", pow(db, da));
    printf("sqrt result: %.2f \n", sqrt(db));
    printf("floor result: %.2f \n", floor(da));
    printf("ceil result: %.2f \n", ceil(da));
    printf("mod result: %.2f \n", fmod(db, da));
}

int
main( void )
{
    t_pow();
	return 1;
}
