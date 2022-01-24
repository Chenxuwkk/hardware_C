#include <stdio.h>
void test01()
{
    char str2[128] = "hello world";
    printf("%s\n", str2);    //读
    printf("%c\n", str2[6]); //读

    str2[6] = 'W';        //不允许给 文字常量区赋值
    printf("%s\n", str2); //读
}

void test02()
{
    int num1 = 10;
    int num2 = 20;
    int num3 = 30;
    int num4 = 40;

    int *arr[4] = {&num1, &num2, &num3, &num4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d ", *arr[i]);
    }
    printf("\n");
}

void test03()
{
    char *arr[4] = {"hehehehe", "xixixixixi", "lalalalala", "hahahahaha"};
    int n = sizeof(arr) / sizeof(arr[0]);

    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }
}

void test04()
{
    int arr[5] = {10, 20, 30, 40, 50};

    //&arr首地址 +1 跳过一个数组
    // printf("arr=%u\n", arr);
    // printf("&arr=%u\n", &arr);
    // printf("&arr+1=%u\n", &arr + 1);
}
void test05()
{
    int arr[5] = {10, 20, 30, 40, 50};

    //数组指针 本质是指针变量
    int(*p)[5] = NULL;
    printf("sizeof(p) =%lu\n", sizeof(p)); //8B

    p = &arr;
    printf("arr[2] = %d\n", *((int *)(p + 1) - 2));
}

void test06()
{
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int row = sizeof(arr) / sizeof(arr[0]);
    int col = sizeof(arr[0]) / sizeof(arr[0][0]);

    int *p = &arr[0][0];

    int i = 0;
    for (i = 0; i < row * col; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    test06();
    return 0;
}
