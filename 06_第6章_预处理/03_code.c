#include <stdio.h>
#define MY_MUL(a, b) a *b
#define MY_MUL2(a, b) ((a) * (b))
void test01()
{
    printf("%d\n", MY_MUL(10, 20));           //10*20
    printf("%d\n", MY_MUL(10 + 10, 20 + 20)); //10 + 10*20 + 20 == 230
    printf("%d\n", MY_MUL2(10 + 10, 20 + 20));//((10 + 10) * (20 + 20))==800
}

void test02()
{
    printf("%d\n", MY_MUL(MY_MUL2(10+10, 20+20), MY_MUL(10+10, 20+20)));
}

int main(int argc, char const *argv[])
{
    test02();
    return 0;
}
