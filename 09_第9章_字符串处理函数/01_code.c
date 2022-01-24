#include <stdio.h>
#include <string.h>
void test01()
{
    char dst[128] = "";
    char src[] = "hello\0world";
    strcpy(dst, src);
    printf("%s\n", dst);

    char dst1[] = "";
    char src1[] = "helloworld";

    strcpy(dst1, src1); //dst1只有1字节 拷贝越界
    printf("%s\n", dst1);
    printf("%s\n", src1);
}

void test02()
{
    char dst[128] = "hello";
    char src[] = "world";
    strcat(dst, src);
    printf("%s\n", dst);
}
void test03()
{
    char s1[128] = "";
    char s2[128] = "";

    printf("请输入第一个字符串:");
    scanf("%s", s1);
    printf("请输入第二个字符串:");
    scanf("%s", s2);

    if (strcmp(s1, s2) > 0)
    {
        printf("%s 大于 %s\n", s1, s2);
    }
    else if (strcmp(s1, s2) < 0)
    {
        printf("%s 小于 %s\n", s1, s2);
    }
    else if (strcmp(s1, s2) == 0)
    {
        printf("%s 等于 %s\n", s1, s2);
    }
}
void test04()
{
    char src[] = "http://www.sex.777.sex.999.sex.com";

    printf("%s\n", src);
    while (1)
    {
        char *ret = strstr(src, "sex");
        if (ret == NULL)
            break;
        memset(ret, '*', strlen("sex"));
    }

    printf("%s\n", src);
}
#include <stdlib.h>
void test05()
{
    printf("%d\n", atoi("100abc"));
    printf("%ld\n", atol("100abc"));
    printf("%f\n", atof("3.14f"));
}

void test06()
{
    char str[] = "hehehe:xixixi::::::hahaha::::::::::::::::::::::::::####lalala:heiheihei:henhenhen:wuwuwu";
    char *buf[32] = {str}; //存放子串的首元素地址

    int i = 0;
    while ((buf[i] = strtok(buf[i], ":#")) && ++i)
        ;

    printf("i=%d\n", i);

    //遍历切割到的子串
    i = 0;
    while (buf[i] != NULL)
    {
        printf("%s\n", buf[i]);
        i++;
    }
}
int msg_deal(char *msg_src, char *msg_done[], char *str)
{
    int i = 0;
    while ((msg_done[i] = strtok(msg_done[i], str)) && (++i))
        ;

    return i;
}
void test07()
{
    char msg_src[] = "+CMGR:REC UNREAD,+8613466630259,98/10/01,18:22:11+00,ABCdefGHI";
    char *msg_done[32] = {msg_src};
    int num = 0;

    num = msg_deal(msg_src, msg_done, ",");

    printf("字符串的數量:%d\n", num);

    int i = 0;
    while (msg_done[i] != NULL)
    {
        printf("%s\n", msg_done[i++]);
    }
}
int my_atoi(char *str)
{
    int sum = 0;
    while (*str >= '0' && *str <= '9')
    {
        sum = sum * 10 + (*str - '0');
        str++;
    }

    return sum;
}
void test08()
{
    char buf[] = "12345abc";

    printf("%d\n", my_atoi(buf));
}
int main(int argc, char const *argv[])
{
    test08();
    return 0;
}
