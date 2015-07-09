/*
** This program test how to use c lib getchar
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
t_len(void)
{
    char * red = "a red story ! ha ha ha";
    char bed[30] = "a bed story  ha ha ha !"; 
    printf("length of red is %d \n", (int)strlen(red));
    printf("length of bed is %d \n", (int)strlen(bed));
}

void
t_cpy(void)
{
    char * red = "a red story ! ha ha ha";
    /* 数组长度改成10后神奇运行，赋值的语句不全，复制的全部打印 */
    char bed[30] = " bed story  violent pron  !"; 
    printf("before copy bed is %s \n", bed);
    strcpy(bed, red);
    printf("after copy bed is %s \n", bed);
}

void
t_cat(void)
{
    char bed[50] = "bed story  violent pron  !"; 
    printf("before cat bed is: %s \n", bed);
    strcat(bed, "zhe hang");
    printf("after cat bed is: %s \n", bed);
}

int
main( void )
{
    t_cat();
	return EXIT_SUCCESS;
}
