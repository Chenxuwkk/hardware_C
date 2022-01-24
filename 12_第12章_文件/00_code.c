#include <stdio.h>
#include <unistd.h>
void test01()
{
    int i = 0;
    while (1)
    {
        printf("\r%02d:%02d", i / 60, i % 60);
        fflush(stdout);
        sleep(1);
        i++;
    }
}

void test02()
{
    fwrite("hello", 6, 1, stdout);
}

void test03()
{
    FILE *fp = NULL;
    fp = fopen("test.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }

    fclose(fp);
}

void test04()
{
    FILE *fp = NULL;
    fp = fopen("test.txt", "w");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }

    char *file_data = "hello world";
    while (*file_data != '\0')
    {
        fputc(*file_data, fp);
        file_data++;
    }

    fclose(fp);
}
void test05()
{
    FILE *fp = NULL;
    fp = fopen("test.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }

    while (1)
    {
        char ch = fgetc(fp);
        if (ch == EOF)
            break;
        printf("%c", ch);
    }

    fclose(fp);
}

void test06()
{
    FILE *fp_r = fopen("test.txt", "r");
    if (fp_r == NULL)
    {
        perror("fopen");
        return;
    }
    FILE *fp_w = fopen("b.txt", "w");
    if (fp_w == NULL)
    {
        perror("fopen");
        return;
    }

    while (1)
    {
        char buf[128] = "";
        //读一行
        char *ret = fgets(buf, sizeof(buf), fp_r);
        if (ret == NULL)
            break;

        //写一行
        fputs(buf, fp_w);
    }

    fclose(fp_r);
    fclose(fp_w);
}

void test07()
{
    
}
int main(int argc, char const *argv[])
{
    test06();
    return 0;
}
