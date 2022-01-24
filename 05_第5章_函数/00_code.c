#include <stdio.h>
void test01()
{
    char arr[5][128] = {""};
    int row = sizeof(arr) / sizeof(arr[0]);
    int col = sizeof(arr[0]) / sizeof(arr[0][0]);

    //获取字符数
    printf("请输入%d个字符串\n", row);
    int i = 0;
    for (i = 0; i < row; i++)
    {
        // scanf("%s", &arr[i][0]);
        scanf("%s", arr[i]);
    }

    printf("-----------------\n");
    //遍历二维字符数组
    for (i = 0; i < row; i++)
    {
        //arr[i] 代表的是 每一行的第0列的列地址
        printf("%s\n", arr[i]);
    }
}
//函数声明  告知编译器 如果遇到函数名为my_add，有两个int形参，以及一个int返回值类型
//请通过编译
//int my_add(int, int);//ok 不推荐
int my_add(int x, int y);

void test02()
{
    int data1 = 10;
    int data2 = 20;

    //函数的调用 data1,data2实参
    int ret = 0;
    ret = my_add(data1, data2);

    printf("结果为:%d\n", ret);
}

//函数的定义 定义处x y叫形参
int my_add(int x, int y) //x = data1, y=data2
{
    //return 返回函数运算结果   结束当前函数
    return x + y;
}
void set_data(int num)
{
    num = 100;
}
void test03()
{
    int data = 0;

    set_data(data);

    printf("data = %d\n", data);
}

void inputIntArray(int arr[], int n);
void printfIntArray(int arr[], int n);
void sortIntArray(int arr[], int n);
void test04()
{
    int arr[5] = {0};
    int n = sizeof(arr) / sizeof(arr[0]);

    //给数组获取键盘输入
    inputIntArray(arr, n);

    //对数组进行排序
    sortIntArray(arr, n);

    //遍历排序后的数组元素
    printfIntArray(arr, n);

    return;
}

#include <string.h>
void my_get_string(char str[], unsigned long n);
int my_strlen(char str[]);
void test05()
{
    char str[128] = "";

    //键盘获取字符串
    my_get_string(str, sizeof(str));

    //定义函数my_strlen测量字符串的参数
    printf("字符串的长度为%d\n", my_strlen(str));
}
int main(int argc, char const *argv[])
{
    test05();
    return 0;
}
int my_strlen(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }

    return i;
}
void my_get_string(char str[], unsigned long n)
{
    printf("请输入一个字符串:");
    fgets(str, n, stdin);
    str[strlen(str) - 1] = 0; //去掉回车

    return;
}

void sortIntArray(int arr[], int n)
{
    int i = 0;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        int j = min + 1;

        for (; j < n; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }

        if (i != min)
        {
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }

    return;
}
void inputIntArray(int arr[], int n)
{
    printf("请输入%d个int元素\n", n);

    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    return; //结束标记
}


void printfIntArray(int arr[], int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return;
}