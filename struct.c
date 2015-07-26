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

void 
t_sa(void)
{
    struct SA{
        char a;
        double b;
        char c;
    }cant_be_init,  *ps;

    /* 测试内存对齐，相同数据类型排列不同占内存不同*/
    /* 这里cant_be_init 不能通过下面方式赋值 只能cant_be_init.a = 'a' 这样赋值*/
    struct SA sa = { 'n', 6.79, 10 };
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

}

void
t_bit(void)
{
    struct WEI{
        unsigned a :4;
        unsigned b :6;
        unsigned c :30;
    } seg, *pw;
    seg.a = 1;
    seg.b = 1;
    seg.c = pow(2,29);
    pw = &seg;
    unsigned long * lp;
    lp = (unsigned long *)pw;
    /* 段以32位为单位，如果超过32位，会从下一个字开始*/
    printf("struct segment bits filed visit  \n");
    printf("value of wei = %s \n", byte_to_binary(*lp));
    printf("value of seg = %x \n", seg);
    printf("value of seg.a = %d \n", seg.a);
    printf("value of seg.c = %d \n", seg.c);
    printf("size of wei = %ld \n", sizeof(seg));
}

typedef struct {
    char a[10];
    float b;
} SA;

void 
t_param(SA aa)
{
    /* 不能用aa.a = "012345" 赋值，array type 'char [10]' is not assignable */
    strcpy(aa.a, "012345");
    aa.b = 8.09;
    printf("on call value of aa.a = %s \n", aa.a);
    printf("on call value of aa.b = %.2f \n", aa.b);
}

int 
main(void){
    SA aa = { "abcdef", 9.0 };
    t_param(aa);
    printf("after call value of aa.a = %s \n", aa.a);
    printf("on call value of aa.b = %.2f \n", aa.b);
    return 0;
}
