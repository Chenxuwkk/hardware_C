#include <stdio.h>
#include <stdbool.h>

//声明区----------------------------------------------------------------
int my_add(int x, int y);
void set_data(int *x); //单向值传递

//----------------------------------------------------------------
void test01()
{
    int data1;
    int data2;
    scanf("%d %d", &data1, &data2);
    int ret = 0;
    ret = my_add(data1, data2);
    printf("ret=%d\n", ret);
}
void test03()
{
    bool num = 0;
    int num[2] = {0};
    int num1 = 0;
    //set_data(num);//传数组名称其实是地址传递，传递过去的是指向该数组的指针
    set_data(&num1);
    printf("num = %d\n", num1);
}
void test04()
{
    int num = 9;
    int *p = &num;
    printf("num1 = %d\n", num);
    printf("num2 = %lu\n", *p);
    printf("num3 = %lu\n", p);

}
int main(int argc, char const *argv[])
{
    test04();
    return 0;
}
void set_data(int *x)
{
    *x = 100;
}
int my_add(int x, int y)
{
    printf("This is my_add\n");
    return x + y;
}