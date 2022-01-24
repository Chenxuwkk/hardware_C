#include <stdio.h>

struct stu
{
    //数据域
    int num;
    char name[32];

    //指针域
    struct stu *next;
};
void test01()
{
    struct stu node1 = {100, "lucy", NULL};
    struct stu node2 = {101, "bob", NULL};
    struct stu node3 = {102, "tom", NULL};
    struct stu node4 = {103, "德玛", NULL};
    struct stu node5 = {104, "小法", NULL};

    //定义链表头
    struct stu *head = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;

    //遍历
    struct stu *pb = head;
    while (pb != NULL)
    {
        //访问数据
        printf("%d %s\n", pb->num, pb->name);

        //pb移动到下一个节点位置
        pb = pb->next;
    }
}
struct name_long1
{
    int a;
    short b;
} DATA2; //DATA2是结构体变量名
typedef struct name_long2
{
    int a;
    short b;
} DATA1; //DATA1是类型

struct name_long_long
{
    int a;
    short b;
};
typedef struct name_long_long DATA3;

typedef struct d
{
    int a;
    short b;
} D_TYPE, *D_POINTER;
void test02()
{
    //D_TYPE ==>struct d
    D_TYPE ob1 = {100, 50};

    //D_POINTER ==>struct d *
    D_POINTER p = &ob1;
    printf("%d %hd\n", p->a, p->b);
}
int main(int argc, char const *argv[])
{
    test02();
    return 0;
}
