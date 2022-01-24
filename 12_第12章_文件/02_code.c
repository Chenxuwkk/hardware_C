#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void print_help();
void get_file_name(char *dest_file_name, char *src_file_name);
char *read_src_file(unsigned long int *file_length, char *src_file_name);
char *file_text_encrypt(char *src_file_text, unsigned long int length, unsigned int password);
void save_file(char *text, unsigned long int length, char *file_name);
int main(int argc, char const *argv[])
{
    while (1)
    {
        char src_file[32] = "";
        char dst_file[32] = "";
        char *data = NULL;
        unsigned long int file_length = 0;
        unsigned int password = 0;

        print_help();
        int cmd = 0;
        scanf("%d", &cmd);

        switch (cmd)
        {
        case 1:
            //获取源文件和目标文件名
            get_file_name(dst_file, src_file);
            //读取源文件的内容
            data = read_src_file(&file_length, src_file);
            //对内容加密
            printf("please input your unsigned int passworld:");
            scanf("%u", &password);
            data = file_text_encrypt(data, file_length, password);
            //对内容保存
            save_file(data, file_length, dst_file);
            break;
        case 2:
            //获取源文件和目标文件名
            //读取源文件的内容
            //对内容解密密
            //对内容保存
            break;
        case 3:
            return 0;
        }
    }
    return 0;
}
void print_help()
{
    printf("********1:加密文件***********\n");
    printf("********2:解密文件***********\n");
    printf("********3:退出程序***********\n");
}
void get_file_name(char *dest_file_name, char *src_file_name)
{
    printf("请输入你的原文件名称(30个字符):");
    scanf("%s", src_file_name);
    printf("请输入你的目的文件名称(30个字符):");
    scanf("%s", dest_file_name);
    return;
}

char *read_src_file(unsigned long int *file_length, char *src_file_name)
{
    FILE *fp = fopen(src_file_name, "r");
    if (fp == NULL)
    {
        perror("fopen");
        exit(-1); //結束進程
    }

    fseek(fp, 0, 2);
    //*file_length == 外界的文件长度变量file_length
    *file_length = ftell(fp);
    rewind(fp);

    //申请空间
    char *p = (char *)calloc(1, *file_length + 1);
    if (p == NULL)
    {
        perror("calloc");
        exit(-1); //結束進程
    }

    //一次性读数据
    fread(p, *file_length, 1, fp);

    fclose(fp);

    return p;
}

char *file_text_encrypt(char *src_file_text, unsigned long int length, unsigned int password)
{
    int i = 0;
    for (i = 0; i < length; i++)
    {
        src_file_text[i] += password;
    }

    return src_file_text;
}
void save_file(char *text, unsigned long int length, char *file_name)
{
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL)
    {
        perror("fopen");
        exit(-1); //結束進程
    }

    fwrite(text, length, 1, fp);

    fclose(fp);

    //释放堆区空间
    if (text != NULL)
    {
        free(text);
        text = NULL;
    }
    return;
}