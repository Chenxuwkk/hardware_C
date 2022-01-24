#include <stdio.h>
#include <string.h>
struct stu
{
    int num; //结构体的成员
    char name[32];
};
void test01()
{
    struct stu lucy = {100, "lucy"};
    //定义一个指针变量p保存lucy的地址
    struct stu *p = &lucy;

    //*p == lucy
    printf("%d %s\n", lucy.num, lucy.name);
    printf("%d %s\n", (*p).num, (*p).name);
    //通过 结构体指针变量 直接访问 结构体空间中的成员
    printf("%d %s\n", p->num, p->name);
    //不管.还是->  就看符号 左边如果是变量 使用.  如果左边是结构体地址 使用->
    printf("%d %s\n", (&lucy)->num, (&lucy)->name);
}

void input_stu_array(struct stu *arr, int n)
{
    printf("请输入%d个学员的信息num name\n", n);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("请输入第%d个学生的信息:", i + 1);
        //scanf("%d %s", &arr[i].num, arr[i].name);
        scanf("%d %s", &(arr + i)->num, (arr + i)->name);
    }
    return;
}
void sort_stu_array(struct stu *arr, int n)
{
    int i = 0;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        int j = min + 1;
        for (; j < n; j++)
        {
            //if(strcmp(arr[min].name, arr[j].name) > 0)
            if (arr[min].num > arr[j].num)
                min = j;
        }

        if (i != min)
        {
            struct stu tmp = arr[min];
            arr[min] = arr[i];
            arr[i] = tmp;
        }
    }
    return;
}
void print_stu_array(struct stu *arr, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        // printf("%d %s\n", arr[i].num, arr[i].name);
        printf("%d %s\n", (arr + i)->num, (arr + i)->name);
    }
    return;
}
void test02()
{
    struct stu edu[5];
    memset(edu, 0, sizeof(edu));
    int n = sizeof(edu) / sizeof(edu[0]);

    //封装函数获取键盘输入
    input_stu_array(edu, n);

    //对结构体数组排序
    sort_stu_array(edu, n);

    //遍历结构体数组的内容
    print_stu_array(edu, n);
}
int main(int argc, char const *argv[])
{
    test02();
    return 0;
}
