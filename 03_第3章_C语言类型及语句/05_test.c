/* ************************************************************************
 *       Filename:  01_test.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2021年07月22日 14时15分26秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/


#include <stdio.h>
int test01()
{
	int data1=-10;
	unsigned int data2 = 6;
	if(data1+data2>0)
	{
		printf(">0\n");
	}
	else
	{
		printf("<=0\n");
	}

	printf("%d\n", data1+data2);
	printf("%u\n", data1+data2);
}
void test02()
{
	int data1=0;
	double data2=0.0;
	printf("%lu\n", sizeof(data1+data2));//8B
}
void test03()
{
	char ch='a';
	short sh=0;
	printf("%lu\n", sizeof(ch+ch));//8B
	printf("%lu\n", sizeof(sh+sh));//8B
	printf("%lu\n", sizeof(ch+sh));//8B

}
void test04()
{
	float f = 3.14f;
	int x = 0;
	x = (int)f;
	printf("x = %d, f=%f\n", x, f);
}
void test05()
{
	printf("%lf\n", 5/2.0);
	
}
#include<stdlib.h>//srand  rand
#include <time.h>//time
void test06()
{
	//设置随机数种子 设置随机数的基础值
	//time(NULL)获取当前时间（1970~现在的所有秒数）
	srand(time(NULL));

	int num = 0;
	num = rand();
	printf("num = %d\n", num%41+60);
}
void test07()
{
	char data = -10;//补码：1111 0110
	printf("移动之前内存数据:%#x\n", data);
	data = data>>4;
	if((data&0xff) == 0xff)
	{
		printf("算术右移\n");
	}
	else if((data&0xff) == 0x0f)
	{
		printf("逻辑右移\n");
	}
}
void test08()
{
	int data1=0, data2=0;

	printf("请输入两个int数据:");
	scanf("%d %d", &data1, &data2);

	printf("最大值为:%d\n", data1>data2?data1:data2);
}
void test09()
{
	int x=0,y=0;

	x = 1,2,3;
	y = (1,2,3);

	printf("x = %d, y=%d\n", x, y);
}
int main(int argc, char *argv[])
{
	test09();
	return 0;
}


