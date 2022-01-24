#include <stdio.h>
#include <string.h>
int my_add(int x, int y)
{
    return x + y;
}
int my_sub(int x, int y)
{
    return x - y;
}
int my_mul(int x, int y)
{
    return x * y;
}
int my_div(int x, int y)
{
    return x / y;
}

int main(int argc, char const *argv[])
{
    char *cmd_buf[] = {"add", "sub", "mul", "div"};
    int n = sizeof(cmd_buf) / sizeof(cmd_buf[0]);
    //函数指针数组
    int (*fun_arr[])(int, int) = {my_add, my_sub, my_mul, my_div};

    while (1)
    {
        printf("请输入计算格式:add 10 20:");
        char cmd[16] = "";
        scanf("%s", cmd);
        if (strcmp(cmd, "quit") == 0)
            break;

        int data1 = 0, data2 = 0;
        scanf("%d %d", &data1, &data2);

        //算法核心
        int i = 0;
        for (i = 0; i < n; i++)
        {
            //相等为0
            if (strcmp(cmd, cmd_buf[i]) == 0)
            {
                printf("结果:%d\n", fun_arr[i](data1, data2));
                break;
            }
        }
    }

    return 0;
}
