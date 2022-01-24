#include <stdio.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
void test01()
{
    char str[128] = "";
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    int i = 0;
    while (str[i] != '\0')
    {
#if MAX_TO_MIN
        //将大写字母转换小写字母
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
#else
        //将小写字符转换成大写字母
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }

#endif
        i++;
    }

    printf("%s\n", str);

    return;
}
int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
