#include <stdio.h>
typedef struct
{
    char name[16];
    int atk;
    int def;
} HERO;
void test01()
{
    HERO hero[] = {{"德玛西亚", 50, 80}, {"小法", 70, 30}, {"盲僧", 80, 80}};
    int n = sizeof(hero) / sizeof(hero[0]);

    FILE *fp = fopen("hero.txt", "w");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }

    fwrite(hero, sizeof(HERO), n, fp);

    fclose(fp);
}

#include <string.h>
void test02()
{
    HERO hero[3];
    memset(hero, 0, sizeof(hero));

    FILE *fp = fopen("hero.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }

    fread(hero, sizeof(HERO), 3, fp);

    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("%s %d %d\n", hero[i].name, hero[i].atk, hero[i].def);
    }

    fclose(fp);
}

void test03()
{
    HERO hero[] = {{"德玛西亚", 50, 80}, {"小法", 70, 30}, {"盲僧", 80, 80}};
    int n = sizeof(hero) / sizeof(hero[0]);

    FILE *fp = fopen("hero.txt", "w");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }

    //格式化写fprintf
    int i = 0;
    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%s %d %d\n ", hero[i].name, hero[i].atk, hero[i].def);
    }

    fclose(fp);
}

void test04()
{
    HERO hero[3];
    memset(hero, 0, sizeof(hero));

    FILE *fp = fopen("hero.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }

    int i = 0;
    for (i = 0; i < 3; i++)
    {
        fscanf(fp, "%s %d %d", hero[i].name, &hero[i].atk, &hero[i].def);
    }

    for (i = 0; i < 3; i++)
    {
        printf("%s %d %d\n", hero[i].name, hero[i].atk, hero[i].def);
    }

    fclose(fp);
}

void test05()
{
    FILE *fp = fopen("c.txt", "w+");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }

    //写
    fputs("hello file", fp);

    long len = ftell(fp);
    printf("文件的大小:%ld\n", len);

    fclose(fp);
}

#include <stdlib.h>
#include <string.h>
void test06()
{
    FILE *fp = fopen("c.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }

    fseek(fp, 0, 2);
    long len = ftell(fp);
    //复位文件流指针
    rewind(fp);
    printf("文件总大小:len=%ld\n", len);

    unsigned char *text = (unsigned char *)calloc(1, len + 1);
    fread(text, len, 1, fp);

    printf("%s\n", text);
    fclose(fp);

    //释放堆区空间（不是必须）
    if (text != NULL)
    {
        free(text);
        text = NULL;
    }
}
int main(int argc, char const *argv[])
{
    test06();
    return 0;
}
