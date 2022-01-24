#include <stdio.h>
enum POKER_COLOR{HONGTAO,MEIHUA=10,FANGKUAI,HEITAO};

void test01()
{
   enum POKER_COLOR p_c = MEIHUA;
   //HONGTAO,MEIHUA,FANGKUAI,HEITAO 枚举列表的值默认从0开始递增
   printf("%d %d %d %d\n", HONGTAO,MEIHUA,FANGKUAI,HEITAO);
   
}
int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
