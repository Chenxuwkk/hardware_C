#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stu
{
    int num;
    char *name; //指针成员
};
void test01()
{
    struct stu lucy;
    lucy.num = 100;
    //让name指向堆区
    lucy.name = (char *)calloc(1, 128);
    strcpy(lucy.name, "hello world");
    printf("%d %s\n", lucy.num, lucy.name);

    struct stu bob;
    bob.name = (char *)calloc(1, 128);
    bob.num = lucy.num;
    strcpy(bob.name, lucy.name);

    printf("%d %s\n", bob.num, bob.name);
    //释放lucy.name指向的堆区空间
    if (lucy.name != NULL)
    {
        free(lucy.name);
        lucy.name = NULL;
    }

    if (bob.name != NULL)
    {
        free(bob.name);
        bob.name = NULL;
    }
}

void test02()
{
    //结构体本身在堆区
    struct stu *p = NULL;
    p = (struct stu *)calloc(1, sizeof(struct stu));

    //为结构体中的指针成员 申请堆区空间
    p->name = (char *)calloc(1, 128);

    //给结构体中的成员赋值
    p->num = 100;
    strcpy(p->name, "hello world");

    printf("%d %s\n", p->num, p->name);

    //先释放成员空间
    if (p->name != NULL)
    {
        free(p->name);
        p->name = NULL;
    }

    //在释放结构体的空间
    if (p != NULL)
    {
        free(p);
        p = NULL;
    }
}

void test03()
{
    //给结构体指针数组申请堆区空间
    struct stu **arr = NULL;
    arr = (struct stu **)calloc(5, sizeof(struct stu *));

    //给指针数组中的每个元素 申请结构体堆区空间
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        arr[i] = (struct stu *)calloc(1, sizeof(struct stu));
        //每个结构体中的name成员申请堆区空间
        arr[i]->name = (char *)calloc(1, 32);

        //赋值
        arr[i]->num = 100 + i;
        sprintf(arr[i]->name, "姓名%d", i + 1);
    }

    //遍历
    for (i = 0; i < 5; i++)
    {
        printf("%d %s\n", arr[i]->num, arr[i]->name);
    }

    //释放arr中的每个元素 以及每个元素中的name
    for (i = 0; i < 5; i++)
    {
        //先释放结构体中的name的指向
        if (arr[i]->name != NULL)
        {
            free(arr[i]->name);
            arr[i]->name = NULL;
        }

        //释放结构体
        if (arr[i] != NULL)
        {
            free(arr[i]);
            arr[i] = NULL;
        }
    }
    //释放整个arr指针数组
    if (arr != NULL)
    {
        free(arr);
        arr = NULL;
    }

    return;
}
int main(int argc, char const *argv[])
{
    test03();
    return 0;
}
