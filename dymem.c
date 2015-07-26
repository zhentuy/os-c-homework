/*
* malloc
* 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
t_all(void)
{
    int * pi;
    pi = malloc(100);
    if( pi == NULL)
    {
        printf("No Mem can user\n");
        exit(1);
    }
    for(int i = 0; i < 25; i++)
    {
        *pi++ = i;
    }
    /* dynamic allocation cant't get it's size */
    printf("arranged mem size of %lu \n", sizeof(pi));
    printf("arranged mem size of *pi %lu \n", sizeof(*pi));
    for(int * pa = pi - 25; pa < pi; pa++)
    {
        printf("value on int list %d \n", *pa);
    }
    free(pi);
}

void
t_cal(void)
{
    /* calloc set all mem with 0 */
    int * pi = calloc(25, sizeof(int));
    if( pi == NULL )
    {
        printf("No Mem can user\n");
        exit(1);
    }
    for(int * pa = pi; pa < pi + 25; pa++)
    {
        printf("value on int list %d \n", *pi);
    }
    free(pi);
}

void
t_err(void)
{
    int a = 100;
    int *p = &a;
    free(p);
    /*  malloc: *** error for object 0x109309040: pointer being freed was not allocated */
    /*  free only can use on malloc, realloc, calloc return's pointer */
}

char *
t_str(char const * old)
{
    char * new;
    new = malloc( strlen(old) + 1 );
    if ( new != NULL )
        strcpy(new, old);
    return new;
}

int 
main(void){
    printf("after malloc %s", t_str("want jojo for fuck"));
    return 1;
}
