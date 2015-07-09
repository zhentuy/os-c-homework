/*
* struct
* 
*/
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <limits.h>
#include <math.h>

const char *byte_to_binary(unsigned long x)
{
    static char b[65];
    b[0] = '\0';

    unsigned long z = pow(2, 63);
    for (; z > 0 ; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

int main(void){

    struct SA{
        char a;
        double b;
        char c;
    } sa, *ps;

    /* 测试内存对齐，相同数据类型排列不同占内存不同*/
    sa.a = 'n';
    sa.b = 6.79;
    sa.c = 10 ;
    ps = &sa;
    int lst = sizeof(sa);

    struct SB{
        char a;
        char c;
        double b;
    } sb;
    int lsb = sizeof(sb);

    printf("struct member visit  \n");
    printf("struct sa.a = %d \n", ps->a);
    printf("struct sa.c = %d \n", (*ps).c);
    printf("struct size with same child but arrange diffrent  \n");
    printf("struct a size = %d \n", lst);
    printf("struct b size = %d \n", lsb);
    printf("offset of  sa.a = %ld \n", offsetof(struct SA, a));
    printf("offset of  sa.b = %ld \n", offsetof(struct SA, b));
    printf("offset of  sa.c = %ld \n", offsetof(struct SA, c));
    printf("offset of  sb.a = %ld \n", offsetof(struct SB, a));
    printf("offset of  sb.b = %ld \n", offsetof(struct SB, b));
    printf("offset of  sb.c = %ld \n", offsetof(struct SB, c));

    struct WEI{
        unsigned a :4;
        unsigned b :6;
        unsigned c :10;
        unsigned d :15;
        unsigned e :15;
    } seg, *pw;
    seg.a = 1;
    seg.b = 1;
    seg.c = 1;
    seg.d = 1;
    seg.e = 1;
    pw = &seg;
    unsigned long * lp;
    lp = (unsigned long *)pw;
    printf("struct segment bits filed visit  \n");
    printf("value of wei = %s \n", byte_to_binary(*lp));
    printf("value of seg.a = %d \n", seg.a);
    printf("size of wei = %ld \n", sizeof(seg));
}
