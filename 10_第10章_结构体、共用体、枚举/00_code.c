#include <stdio.h>

//定义结构体类型 系统是不分配空间
struct stu
{
    //定义类型是 不要给成员赋值
    //int num = 10; //error
    int num; //结构体的成员
    char name[32];

}; //必须有分号
void test01()
{
    struct stu lucy;

    //访问结构体成员  必须遵循成员自身的类型
    printf("%d %s\n", lucy.num, lucy.name);
}

void test02()
{
    //结构体变量的初始化  必须遵循成员的顺序以及自身的类型
    struct stu lucy = {100, "lucy"};

    printf("%d %s\n", lucy.num, lucy.name);
}
#include <string.h>
void test03()
{
    struct stu lucy;
    //使用memset给结构体变量清空
    memset(&lucy, 0, sizeof(lucy));

    printf("请输入num name:");
    //&lucy.num 取的是lucy中num成员的地址
    scanf("%d %s", &lucy.num, lucy.name);

    printf("%d %s\n", lucy.num, lucy.name);
}

void test04()
{
    struct stu lucy = {100, "lucy"};
    struct stu bob;

#if 0
    //方式一：逐个成员赋值
    bob.num = lucy.num;
    strcpy(bob.name, lucy.name);
#elif 0
    //方式二：相同类型的结构体变量 可以直接赋值 （推荐）
    bob = lucy;
#else
    //方式三：相同类型的结构体变量 内存赋值
    memcpy(&bob, &lucy, sizeof(lucy));
#endif

    printf("%d %s\n", bob.num, bob.name);
}

struct Date
{
    int year;
    int month;
    int day;
};

struct student
{
    int num;
    char name[32];
    struct Date ob;
};

void test05()
{
    struct student lucy = {100, "lucy", {2021, 7, 30}};
    //结构体嵌套结构体 访问到最底层
    printf("num = %d, name=%s\n", lucy.num, lucy.name);
    printf("%d %d %d\n", lucy.ob.year, lucy.ob.month, lucy.ob.day);
}

struct stu2
{
    int num; //结构体的成员
    char name[32];
};
void test06()
{
    struct stu2 edu[5] = {{100, "lucy"}, {101, "bob"}, {102, "tom"}, {103, "德玛西亚"}, {104, "小炮"}};
    //memset(edu, 0,sizeof(edu));//将整个结构体数组清0
    int n = sizeof(edu) / sizeof(edu[0]);

    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d %s\n", edu[i].num, edu[i].name);
    }
}

void test07()
{
    struct stu2 edu[5];
    memset(edu, 0, sizeof(edu)); //将整个结构体数组清0
    int n = sizeof(edu) / sizeof(edu[0]);

    printf("请输入%d个学生信息num name\n", n);
    //获取键盘输入
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d %s", &edu[i].num, edu[i].name);
    }

    for (i = 0; i < n; i++)
    {
        printf("%d %s\n", edu[i].num, edu[i].name);
    }
}
int main(int argc, char const *argv[])
{
    test07();
    return 0;
}
