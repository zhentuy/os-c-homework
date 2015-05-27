/*
 *  when  calling funcation do not know funcation prototype, will return int.
 *  测试当程序调用一个无法见到原型的函数时，编译器会认为这个函数返回一个整形值
 *  如果函数声明在main后面，切返回值为int的时候，会报下面错误
 *
 *  zhu@iZ2824d2ivyZ:~/learn/cs$ gcc func_protype.c
 *  func_protype.c:15:7: error: conflicting types for ‘func’
 *   float func(void){
 *          ^
 *   func_protype.c:11:15: note: previous implicit declaration of ‘func’ was here
 *   float x = func() * y;
 *              ^
*/

#include <stdio.h>

float func(void){
    return 3.54;
}

int main(){
    int  y=10;
    float x = func() * y;
    printf("x = 10*y = %f,  y=%d\n", x, y);
}
