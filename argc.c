/*
* argument
* 
*/
#include <stdio.h>
#include <stdlib.h>

int 
main(int argc, char ** argv){
    printf("there are  %d  params\n", argc);
    while( *argv++ != NULL)
        /* 会打印队列尾部null，因为进入while后argv值已经增加 */
        printf("args  %s  \n", *argv);
    return EXIT_SUCCESS;
}
