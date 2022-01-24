#include <stdio.h>

void set_data01(int d) //int d = num
{
    d = 100;
    return;
}
void set_data02(int *p) //int *p = &num;
{
    //p == &num   --> *p = num
    *p = 100; //num = 100
}
void test01()
{
    int num = 0;

    //set_data01(num); //传值
    set_data02(&num);

    printf("num = %d\n", num);
}

//一维数组作为函数的形参  会被编译器 优化成  指针变量
//void printf_int_array(int p[5], int n)
void printf_int_array(int *p, int n)
{
    printf("sizeof(p)=%lu\n", sizeof(p)); //8B
    int i = 0;
    for (i = 0; i < n; i++)
    {
        //printf("%d ", *(p+i));
        printf("%d ", p[i]);
    }
    printf("\n");
}
void test02()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("sizeof(arr)=%lu\n", sizeof(arr)); //20B
    printf_int_array(arr, n);
}
void input_int_array(int *p, int n)
{
    printf("请输入%d个int数据:", n);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }
    return;
}
void get_max_min_data(int *arr, int *p_max, int *p_min, int n)
{
    int max = arr[0], min = arr[0];

    int i = 0;
    for (i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
        if (min > arr[i])
            min = arr[i];
    }

    //*p_max = 外部max  *p_min==外部的min
    *p_max = max;
    *p_min = min;

    return;
}
void test03()
{
    int arr[5] = {0};
    int n = sizeof(arr) / sizeof(arr[0]);

    //获取键盘输入
    input_int_array(arr, n);

    //求最大最小值
    int max = 0, min = 0;
    get_max_min_data(arr, &max, &min, n);
    printf("max=%d, min=%d\n", max, min);
}

void my_fun(int *p)
{
    p[0] = p[1];
    return;
}
void test04()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    int i = 0;
    for (i = 0; i < n - 1; i++)
    {
        my_fun(&arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//二维数组 作为函数的形参 会被优化成 一维的数组指针
//void printf_int_two_array(int arr[3][4], int row, int col)
void printf_int_two_array(int (*arr)[4], int row, int col)
{
    printf("内部sizeof(arr)=%lu\n", sizeof(arr)); //8B
    int i = 0, j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return;
}
void test05()
{
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int row = sizeof(arr) / sizeof(arr[0]);
    int col = sizeof(arr[0]) / sizeof(arr[0][0]);

    printf("外部sizeof(arr)=%lu\n", sizeof(arr)); //48B
    printf_int_two_array(arr, row, col);
}

void get_addr(int **q) //int **q = &p;
{
    static int data = 10;
    //q==&p
    //*q == *&p ==p
    //p = &data
    *q = &data;
    return;
}
void test06()
{
    int *p = NULL;
    get_addr(&p); //p=&data

    printf("*p = %d\n", *p); //*p == data
}
int my_add(int x, int y)
{
    return x + y;
}
void test07()
{
    printf("%p\n", my_add);
    int ret = ((int (*)(int, int))(0x400c0f))(10, 30);
    printf("%d\n", ret);
}
int main(int argc, char const *argv[])
{
    test07();
    return 0;
}
