/*
    when  calling funcation do not know funcation prototype, will return int.
    测试当程序调用一个无法见到原型的函数时，编译器会认为这个函数返回一个整形值
    如果函数声明在main后面，并且返回值不为int的时候，会报下面错误

        float func(void){
            return 3.54;
        }
    zhu@iZ2824d2ivyZ:~/learn/cs$ gcc func_protype.c
    func_protype.c:15:7: error: conflicting types for ‘func’
    float func(void){
         ^
    func_protype.c:11:15: note: previous implicit declaration of ‘func’ was here
    float x = func() * y;
             ^
    当函数声明在main后面，并且返回值不是int时，编译报两个警号。

        int func(void){
            return 3.54;
        }

    ➜  os-c-homework git:(master) ✗ gcc func_no_prototype.c
    func_no_prototype.c:19:15: warning: implicit declaration of function 'func' is invalid in C99 [-Wimplicit-function-declaration]
        float x = func() * y;
                  ^
    func_no_prototype.c:24:12: warning: implicit conversion from 'double' to 'int' changes value from 3.54 to 3 [-Wliteral-conversion]
        return 3.54;
        ~~~~~~ ^~~~
    2 warnings generated.
    运行时返回值被转换成int类型
    x = 10*y = 30.000000,  y=10
*/

#include <stdio.h>

int main(){
    int  y=10;
    float x = func() * y;
    printf("x = 10*y = %f,  y=%d\n", x, y);
}

int func(void){
    return 3.54;
}

