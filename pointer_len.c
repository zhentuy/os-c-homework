#include <stdio.h>
/*
* poniter length any diffrent ?
* 起始在特定机器上，指针长度都一样。不同的是解释指针的方式
*/

int main(void){
    int name[10];
    int u = sizeof(name);
    printf("array name size = %d, uu = %u \n", u, u);

    int * pa = 100;
    int la = sizeof(pa);
    printf("array name size = %d, uu = %u \n", la, la);

    char * pc = 'b';
    int lc = sizeof(pc);
    printf("array name size = %d, uu = %u \n", lc, lc);

    double da = 8.99;
    double * pf = &da;
    int lf = sizeof(pf);
    printf("array name size = %d, uu = %u \n", lf, lf);

    struct {
        char a;
        double b;
        char c;
    } sa, *ps;

    sa.a = 'n';
    sa.b = 6.79;
    sa.c = 10 ;
    ps = &sa;
    int lst = sizeof(ps);
    printf("struct size = %d, uu = %u \n", lst, lst);
}
