
//extern 声明data为int类型 来之其他源文件
extern int data;
static void add_data(void)
{
    data = data + 100;
    return;
}