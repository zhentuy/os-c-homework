/*
* link
* 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
    struct NODE *link;
    int value;
} Node;

int 
sll_insert(Node * current, int new_value)
{
    Node * pre = current;
    Node * new;
    /* 必须有起始节点 */
    if(current == null)
        return -1

    while(current != NULL && current->value < new_value){
        pre = current;
        current = current->link;
    }

    new = (Node *)malloc( sizeof(Node));
    if (new == NULL)
        return 0;
    new->value = new_value;
    if(current != NULL){
        if( pre != current ){
            new->link = current;
            pre->link = new;
        }
        else{
            /* 插入到开头 */
            new->link = pre;
            pre = new;
        }
    }
    else{
        /* 插入尾部  */
        pre->link = new;
        new->link = NULL;
    }

    return 1;
}

int 
main(void){
    Node e = { NULL, 100 };
    Node a = { &e , 10 };
    Node * root = &a;
    int res = sll_insert(root, 509);
    printf("returen  value is : %d, \n", res);
    int i = 0;
    Node *p = root;
    /* 最后一个节点无法访问 */
    for(; p->link != NULL; p=p->link, i++){
        printf("node %d s value is : %d, \n", i, p->value);
    }
    printf("node %d s value is : %d, \n", i, p->value);
    return 0;
}
