#include <stdio.h>

void test01()
{
    //num为只读  只能初始化 不能被赋值
    const int num = 10;
    // num = 100; //err
    printf("num = %d\n", num);
}
void test02()
{
    int num = 10;
    //p只读  *p只读
    const int *const p = &num;
    //*p = 100;//error

    int data = 20;
    //p = &data; //error
    printf("*p = %d\n", *p);
}
int main(int argc, char const *argv[])
{
    test02();
    return 0;
}
