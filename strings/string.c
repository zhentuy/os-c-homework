/*
** learn stlib string function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void
t_len(void)
{
    char * red = "a red story ! ha ha ha";
    char bed[30] = "a bed story  ha ha ha !"; 
    /* 当数组不能容纳时，编译有warning， 运行打印出后面数据 */
    char sm[3] = "aaaaa";
    int a[30];
    printf("length of red is %d \n", (int)strlen(red));
    printf("length of bed str is %d \n", (int)strlen(bed));
    printf("length of bed is %lu \n", sizeof(bed));
    printf("length of a is %lu \n", sizeof(a));
    printf("length %s of sm is %lu \n", sm, sizeof(sm));
}

void
t_cpy(void)
{
    char * red = "a red story ! ha ha ha";
    char * numb = "0123456789";
    /* 数组长度改成10后神奇运行，赋值的语句不全，复制的全部打印 */
    char bed[30] = " bed story  violent pron  !"; 
    char nbed[30];
    printf("before copy bed is: \n  %s \n", bed);
    strcpy(bed, red);
    printf("after copy bed is: \n  %s \n", bed);
    /* 因为strncpy操作可能不是一个字符串，只要空间足够，在字符串后面添加NUL结尾
    但是在目的地已经有值得时候，竟然没给加，所以结尾还是原先的值 */
    strncpy(nbed, numb, 5);
    strncpy(bed, numb, 5);
    printf("after n copy bed is: \n  %s \n", bed);
    printf("after n copy bed length is: \n  %lu \n", strlen(bed));
    printf("after n copy nbed is: \n  %s \n", nbed);
    printf("after n copy nbed length is: \n  %lu \n", strlen(nbed));
}

void
t_cat(void)
{
    char bed[50] = "bed story  violent pron  !"; 
    printf("before cat bed is: \n %s \n", bed);
    strcat(bed, "zhe hang");
    printf("after cat bed is: \n  %s \n", bed);
    strncat(bed, "0123456789", 9);
    printf("after n cat bed is: \n  %s \n", bed);
}

void
t_cmp(void)
{
    char * red = "a red story ! ha ha ha";
    char bed[30] = "a bed story  ha ha ha !"; 
    printf("compare of red is %d \n", strcmp(red, bed));
    printf("2n compare of red is %d \n", strncmp(red, bed, 2));
}

void
t_find(void)
{
    char bed[30] = "0123456cisc01234567";
    int b = 'c';
    char * taget = strchr(bed, b);
    printf("find %c in %s is: \n  %s \n", b, bed, taget);
    printf("find %c in %s in: \n  %ld \n", b, bed, taget - bed);
    char * rtaget = strrchr(bed, b);
    printf("find %c in %s is: \n  %s \n", b, bed, rtaget);
    printf("find %c in %s in: \n  %ld \n", b, bed, rtaget - bed);

    char * c = "is";
    char * staget = strpbrk(bed, c);
    printf("find '%s' in %s is: \n  %s \n", c, bed, staget);
    printf("find '%s in %s in: \n  %ld \n", c, bed, staget - bed);
    char * mtaget = strstr(bed, c);
    printf("find '%s' in %s is: \n  %s \n", c, bed, mtaget);
    printf("find '%s in %s in: \n  %ld \n", c, bed, mtaget - bed);
}

void
t_search(void)
{
    char bed[30] = "        0123456cisc01234567";
    char * b = " 012";
    char * c = "c";
    int taget = strspn(bed, b);
    printf("strspn  %s in %s is: \n  %d \n", b, bed, taget);
    /* 打印不全是因为strtok 改变了原字符串 */
    char * mtaget = strtok(bed, c);
    printf("token  %s in %s is: \n  %s \n", c, bed, mtaget);
    char * ntaget = strtok(NULL, c);
    printf("token  %s in %s is: \n  %s \n", c, bed, ntaget);
}


void
t_chr(void)
{
    char b = '9';
    char c = 'c';
    printf("isspace  '%c' :  %d \n", b, isspace(b));
    printf("isxdigit  '%c' :  %d \n", b, isxdigit(b));
    printf("isxdigit  '%c' :  %d \n", c, isxdigit(c));
    printf("isupper  '%c' :  %d \n", c, isupper(c));
    printf("isgraph  '%c' :  %d \n", c, isgraph(c));
}

void
t_mem(void)
{
    char *b = "0123456789";
    char c[11];
    /* 难道初始话数组的时候编译器填充NUL了？ 下面这行打印为空，
    在下一个打印能正常结束，但是没有copy到NUl */
    printf("before memcpy  :\n  %s \n",  c);
    memcpy(c, b, 9);
    printf("after memcpy   :\n  %s \n",  c);
    memmove(c, c+1, 9);
    printf("after memmove   :\n  %s \n",  c);
    memset(c, 'x', 9);
    printf("after memset   :\n  %s \n",  c);
    printf("memcmp   :\n  %d \n",  memcmp(c, b, 5));
    printf("memchr   :\n  %s \n",  (char*)memchr(b, '5', 7));
}

void
t_uni(void)
{
    union {
        int a;
        float b;
        char c[4];
    } x = {5};

    x.b = 3.14;
    printf("union  int value :  %d \n",  x.a);
    printf("union  float value :  %f \n",  x.b);
    printf("union  char value :  %s \n",  (char*)x.c);
}

int
main( void )
{
    t_len();
	return EXIT_SUCCESS;
}
