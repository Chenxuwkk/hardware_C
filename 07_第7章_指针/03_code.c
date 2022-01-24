#include <stdio.h>
int my_add(int x, int y)
{
    return x + y;
}
int my_sub(int x, int y)
{
    return x - y;
}
int my_mul(int x, int y)
{
    return x * y;
}
int my_div(int x, int y)
{
    return x / y;
}

//设计算法 完成加减乘除
int my_calc(int d1, int d2, int (*func)(int, int))
{
    return func(d1, d2);
}
int main(int argc, char const *argv[])
{
    printf("%d\n", my_calc(10, 20, my_add));
    printf("%d\n", my_calc(10, 20, my_sub));
    printf("%d\n", my_calc(10, 20, my_mul));
    printf("%d\n", my_calc(10, 20, my_div));

    return 0;
}
