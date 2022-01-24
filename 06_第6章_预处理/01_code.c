#include <stdio.h>
#if 1
void test01()
{
    int arr[5] = {0};

    printf("%p\n", arr);
    printf("%p\n", &arr[0]);
}

void test02()
{                 //复合语句
    int num = 10; //num 局部变量
    {
        int num = 20;        //data 局部变量
        printf("%d\n", num); //20 就近原则
    }
    printf("%d\n", num); //10
}

extern void add_data(void);
int data = 10; //普通全局变量
void test03()
{
    add_data();
    printf("data = %d\n", data);
}
#endif
void fun04()
{
    static int num = 10;
    num++;
    printf("num = %d\n", num);
}
void test04()
{
    fun04();
    fun04();
    fun04();
    fun04();
}
int data3 = 10;        //普通全局变量
static int data4 = 20; //静态全局变量
void test05()
{
}
int main(int argc, char const *argv[])
{
    test05();
    return 0;
}
