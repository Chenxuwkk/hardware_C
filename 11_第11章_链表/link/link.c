#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"

#if 0
//头部之前插入
STU *insert_link(STU *head, STU tmp)
{
    //为待插入的数据申请 空间
    STU *pi = (STU *)calloc(1, sizeof(STU));
    if (pi == NULL)
    {
        perror("calloc");
        exit(-1); //结束进程
    }
    //将tmp数据赋值到 *pi
    *pi = tmp;
    pi->next = NULL;

    //判断链表是否存在
    if (head == NULL) //不存在
    {
        head = pi;
        //return head;
    }
    else //存在
    {
        pi->next = head;
        head = pi;
        //return head;
    }

    return head;
}
#endif

#if 1
//尾部插入
STU *insert_link(STU *head, STU tmp)
{
    //为待插入的数据申请 空间
    STU *pi = (STU *)calloc(1, sizeof(STU));
    if (pi == NULL)
    {
        perror("calloc");
        exit(-1); //结束进程
    }
    //将tmp数据赋值到 *pi
    *pi = tmp;
    pi->next = NULL;

    //判断链表是否存在
    if (head == NULL) //不存在
    {
        head = pi;
        //return head;
    }
    else //存在
    {
        //寻找链表的尾节点
        STU *pb = head;
        while (pb->next != NULL)
        {
            pb = pb->next;
        }

        //pb就是尾节点
        pb->next = pi;
    }

    return head;
}
#endif

#if 0
//有序插入
STU *insert_link(STU *head, STU tmp)
{
    //为待插入的数据申请 空间
    STU *pi = (STU *)calloc(1, sizeof(STU));
    if (pi == NULL)
    {
        perror("calloc");
        exit(-1); //结束进程
    }
    //将tmp数据赋值到 *pi
    *pi = tmp;
    pi->next = NULL;

    //判断链表是否存在
    if (head == NULL) //不存在
    {
        head = pi;
        //return head;
    }
    else //存在
    {
        //寻找插入点的位置
        STU *pb = head, *pf = head;
        while ((pb->num < pi->num) && (pb->next != NULL))
        {
            pf = pb;
            pb = pb->next;
        }

        if (pb->num >= pi->num) //头部，中部插入
        {
            if (head == pb) //头部之前插入
            {
                pi->next = head;
                head = pi;
            }
            else //中部插入
            {
                pf->next = pi;
                pi->next = pb;
            }
        }
        else //尾部插入
        {
            pb->next = pi;
        }
    }

    return head;
}
#endif
void print_link(STU *head)
{
    //判断链表是否存在
    if (head == NULL)
    {
        printf("link not exits\n");
        return;
    }
    else
    {
        STU *pb = head;
        while (pb != NULL)
        {
            printf("%d %s %f\n", pb->num, pb->name, pb->score);
            pb = pb->next;
        }
    }
    return;
}

STU *search_link(STU *head, char *name)
{
    //判断链表是否存在
    if (NULL == head)
    {
        printf("link not exist\n");
        return NULL;
    }
    else //链表存在
    {
        STU *pb = head;
        while ((strcmp(pb->name, name) != 0) && (pb->next != NULL))
        {
            pb = pb->next;
        }

        //找到
        if (strcmp(pb->name, name) == 0)
        {
            return pb;
        }
    }

    printf("未找到相关数据\n");
    return NULL;
}

STU *delete_link(STU *head, int num)
{
    //判断链表是否存在
    if (NULL == head)
    {
        printf("link not exist\n");
        return head;
    }
    else
    {
        //查找删除的点
        STU *pb = head, *pf = head;
        while ((pb->num != num) && (pb->next != NULL))
        {
            pf = pb;
            pb = pb->next;
        }

        if (pb->num == num) //找到
        {
            //判断删除点的位置
            if (pb == head) //删除头节点
            {
                head = head->next;
                //free(pb);
            }
            else //删除中尾部节点
            {
                pf->next = pb->next;
                //free(pb);
            }
            free(pb);
            printf("已成功删除num=%d的节点\n", num);
        }
        else //未找到
        {
            printf("未找到需要删除的节点\n");
        }
    }

    return head;
}

STU *free_link(STU *head)
{
    //判断链表是否存在
    if (NULL == head)
    {
        printf("link not exist\n");
    }
    else
    {
        STU *pb = head;
        while (pb != NULL)
        {
            head = pb->next;
            free(pb);
            pb = head;
        }
    }
    return NULL;
}

STU *reverse_link(STU *head)
{
    //判断链表是否存在
    if (NULL == head)
    {
        printf("link not exist\n");
        //return head;
    }
    else
    {
        STU *pb = head->next;
        STU *pn = NULL;
        head->next = NULL;

        while (pb != NULL)
        {
            //纪录pb下一个节点位置
            pn = pb->next;
            //pb连接上一个节点
            pb->next = head;
            head = pb;
            pb = pn;
        }

        printf("链表翻转成功\n");
    }

    return head;
}

void sort_link(STU *head)
{
    //判断链表是否存在
    if (NULL == head)
    {
        printf("link not exist\n");
        return;
    }
    else
    {
        STU *p_i = head, *p_j = head; //int i=0,j=0;
        while (p_i->next != NULL)     //for(i=0;i<n-1;i++)
        {
            STU *p_min = p_i;   //int min = i;
            p_j = p_min->next;  //j=min+1;
            while (p_j != NULL) //for(;j<n;j++)
            {
                if (p_min->num > p_j->num) //if(arr[min] > arr[j])
                    p_min = p_j;           //min = j;

                p_j = p_j->next; //j++
            }
            if (p_i != p_min) //if(i != min)
            {
                //交换数据
                STU tmp = *p_i;
                *p_i = *p_min;
                *p_min = tmp;

                tmp.next = p_i->next;
                p_i->next = p_min->next;
                p_min->next = tmp.next;
            }

            p_i = p_i->next; //i++
        }
    }
    return;
}