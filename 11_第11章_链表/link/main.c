#include <stdio.h>
#include <string.h>
#include "link.h"
STU *head = NULL; //一定要初始化为NULL
void help(void)
{
    printf("*******************************\n");
    printf("*help:帮助信息                *\n");
    printf("*insert:插入链表节点          *\n");
    printf("*print:遍历链表节点           *\n");
    printf("*search:查询链表某个节点      *\n");
    printf("*delete:删除链表某个节点      *\n");
    printf("*free:释放整个链表            *\n");
    printf("*quit:退出程序                *\n");
    printf("*reverse:翻转链表             *\n");
    printf("*sort:链表排序                *\n");
    printf("*******************************\n");
}
int main(int argc, char const *argv[])
{
    help();
    while (1)
    {
        char cmd[128] = "";
        printf("请输入操作命令:");
        scanf("%s", cmd);

        if (strcmp(cmd, "help") == 0)
        {
            help();
        }
        else if (strcmp(cmd, "insert") == 0)
        {
            printf("请输入需要插入的学生信息num name score:");
            STU tmp;
            scanf("%d %s %f", &tmp.num, tmp.name, &tmp.score);

            //将tmp插入到链表中
            head = insert_link(head, tmp);
        }
        else if (strcmp(cmd, "print") == 0)
        {
            print_link(head);
        }
        else if (strcmp(cmd, "search") == 0)
        {
            printf("请输入要查找的姓名:");
            char name[128] = "";
            scanf("%s", name);
            STU *ret = search_link(head, name);
            if (ret != NULL)
            {
                printf("查询的结果:%d %s %f\n", ret->num, ret->name, ret->score);
            }
        }
        else if (strcmp(cmd, "delete") == 0)
        {
            printf("请输入要删除的学号:");
            int num = 0;
            scanf("%d", &num);

            head = delete_link(head, num);
        }
        else if (strcmp(cmd, "free") == 0)
        {
            head = free_link(head);
        }
        else if (strcmp(cmd, "quit") == 0)
        {
            head = free_link(head);
            break;
        }
        else if (strcmp(cmd, "reverse") == 0)
        {
            head = reverse_link(head);
        }
        else if (strcmp(cmd, "sort") == 0)
        {
            sort_link(head);
        }
    }
    return 0;
}
