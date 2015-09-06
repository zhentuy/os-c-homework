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

void
t_div(void)
{
    div_t rr;
    rr = div(7, -3);
    printf("result of div div_t->quot: %d \n", rr.quot);
    printf("result of div div_t->rem: %d \n", rr.rem);
    int rd = 7/-3;
    int rm = 7%-3;
    printf("result of div //: %d \n", rd);
    printf("result of div %%: %d \n", rm);

}
int
main( void )
{
    t_div();
	return 1;
}
