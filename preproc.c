/*
* homework for prprocessing
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
t_predef(void)
{
    printf("__FILE__  is %s \n", __FILE__);
    printf("__LINE__  is %d \n", __LINE__);
    printf("__DATE__  is %s \n", __DATE__);
    printf("__TIME__  is %s \n", __TIME__);
    printf("__STDC__  is %d \n", __STDC__);
}

void
t_def(void)
{
    /* do not add ';' on define end */
    #define num 123
    printf("define int is %d \n", num);
    #define name "abcdefg"
    printf("define str is %s \n", name);

    /* def name(parameter-list) stuff */
    /* use "()" to prevent x+1 * x+1  */
    #define ADD(x, y)  (x) + (y)
    int x = 10, y=90000;
    printf("ADD int x=%d y=%d  is %d \n", x, y, ADD(x, y));
    float x1 = 10, y1=90000;
    printf("ADD float x1=%f y1=%f  is %.3f \n", x1, y1, ADD(x1, y1));

    /* marco param insert to string */
    /* border string join together automatic */
    #define PRINT(format, value) printf("the value is " format "\n", value)
    PRINT("i from %s ", "shandong");
    /* turn param to string #param1 */
    #define PRINT1(format, value) printf("the value of " #value " is " format "\n", value)
    PRINT1("%d ", x * 1000 );
    /* ## */
    int v1=0, v2=0, v3=0;
    #define ADD_TO(add_num, value) printf("the value of v" #add_num  " is %d \n", v##add_num += value)
    ADD_TO(1, 99999);
    ADD_TO(2, 88888);
    ADD_TO(3, 777777);
    /* ADD_TO('3', 777777); fall */
}

#define is_zhu 1
#if is_zhu
    printf("happy zhu");
#else
    printf("happy wang");

void
t_ifdef(void)
{
    int is_zhu = 1;
}

int
main( void )
{
    t_ifdef();
	return EXIT_SUCCESS;
}
