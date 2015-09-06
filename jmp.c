/*
** how to use setjmp
*/
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf begin;

void
step11(void)
{
    printf("in setp 11 \n");
    longjmp(begin, 10);
}

void
step1(void)
{
    step11();
    // never excute 
    printf("in setp 1 \n");
}

int
main( void )
{
    int value;
    value = setjmp(begin);
    printf("just setjmp return value is %d \n", value);
    if(value == 0){
        step1();
    }
    value = setjmp(begin);
    printf("after longjmp return value is %d \n", value);
	return 1;
}
