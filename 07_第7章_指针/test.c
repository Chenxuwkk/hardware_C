#include <stdio.h>
void test01()
{
    int num = 10;
    int *p;
    p = &num;
    //星号其实是表示p是个指针变量，定义后 p 为指针变量
    // p中存的是地址  *p是 指向处 的值
    // p = &num
    // *p = *&num == num
    printf("num = %d\n", *p);
    return;
}
void test02()
{
    //指针初始化
    int *p = NULL;
    // 1
    //(void *)1  //将1 强制类型转化为地址1
    return;
}

void test03()
{
    //初始化为合法地址
    int num = 10;
    int *p = &num;
    // and
    int data = 0, *p = &data;
}
int main(int argc, char const *argv[])
{
    test02();
    return 0;
}