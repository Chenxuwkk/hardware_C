#include <stdio.h>
void test01()
{
    printf("%lu\n", sizeof(char *));
    printf("%lu\n", sizeof(short *));
    printf("%lu\n", sizeof(int *));
    printf("%lu\n", sizeof(long *));
    printf("%lu\n", sizeof(float *));
    printf("%lu\n", sizeof(double *));
    printf("%lu\n", sizeof(int *********));
}
void test02()
{
    int num = 10;
    int *p;

    //建立关系
    p = &num;

    //%p 打印地址编号
    printf("p = %p\n", p);
    printf("&num = %p\n", &num);

    printf("num = %d\n", num);
    printf("*p = %d\n", *p);
}
void test03()
{
    //NULL的本质 地址编号0
    int *p = NULL;

    printf("*p = %d\n", *p);
}

void test04()
{
    int num = 10;
    int *p = &num;

    //在使用中
    //num 为int    &num 为int *   ---->对变量名 取地址 整体类型加一个*
    //p 为int *    *p 为int       ---->对指针变量 取*  整体类型减一个*

    //在使用中  &和*相遇  从右往左 依次抵消
    *&p == p;
}

void test05()
{
    int num = 0x01020304;

    int *p1 = &num;
    printf("%#x\n", *p1);

    short *p2 = (short *)&num;
    printf("%#x\n", *p2);

    char *p3 = (char *)&num;
    printf("%#x\n", *p3);
}

void test06()
{
    int num = 0x01020304;
    char *p1 = (char *)&num;
    printf("%#x\n", *(short *)(p1 + 1));
}

void test07()
{
    int num = 0;
    int *p = &num;

    //p ==&num
    // scanf("%d", &num);
    scanf("%d", p);
    printf("num = %d\n", num);

    //num = 100;
    //*p == num
    *p = 100;
    printf("num = %d\n", num);

    //num++
    (*p)++; //*p = *p+1
    printf("num = %d\n", num);
}

void test08()
{
    int num = 10;
    void *p = &num;

    printf("%d\n", *(int *)p);
}

void test09()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int *p = arr;
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void test10()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("arr[1] = %d\n", arr[1]);
    printf("*(arr+1) = %d\n", *(arr + 1));
    printf("--------------------\n");
    printf("*(arr+1) = %d\n", *(1 + arr));
    printf("1[arr] = %d\n", 1 [arr]);

    //[]是*（）的缩写  []左边的值 放在+的左边  []里面的值 放在+右边  整体取*
}
int main(int argc, char const *argv[])
{
    test10();
    return 0;
}
