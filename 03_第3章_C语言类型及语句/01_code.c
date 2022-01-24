/********************************************************
* Author       : Chenxuwkk 
* Last modified: 2022-01-23 13:51
* Email        : 1689204123@qq.com
* Filename     : 01_code.c
* Description  : My C program 
********************************************************/
/* ************************************************************************
 *       Filename:  01_code.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2021年07月21日 11时07分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/

#include <stdio.h>
void test01()
{
	//'\n' 换行  刷新缓冲区
	printf("%c\n", 'a');
	printf("%d\n", 10);
	printf("%hd\n", 10);
	printf("%ld\n", 10L);
	printf("%f\n", 3.14f);
	printf("%lf\n", 3.14);
	printf("%s\n", "hello world");
}

int data; //在函数外定义的变量 全局变量
void test02()
{
	//{}复合语句  在复合语句中定义的变量为  局部变量
	//如果局部变量不初始化 内容不确定
	int num = 0;

	printf("num = %d\n", num); //读操作

	int data = num; //num读  data写

	data = 100; //data 写
	if (data > 100)
		; //data 读

	data++; //data = data+1
}
//变量声明  extern显示声明  不会给变量开辟空间 声明的时候不要给变量赋值
extern int data2;
void test03()
{
	//变量的使用
	printf("data2 = %d\n", data2);
}

//变量定义 给data2开辟4字节空间  data2代表这4字节空间的内容
int data2 = 0;
void test04()
{
	int num = 0;

	printf("请输入一个int数据:");
	scanf("%d", &num);

	printf("num = %d\n", num);
}

void test05()
{
	//int data1=0;
	//int data2=0;
	int data1 = 0, data2 = 0;

	printf("请输入两个int数据:");
	scanf("%d %d", &data1, &data2);

	if (data1 > data2)
	{
		printf("最大值为:%d\n", data1);
	}
	else
	{
		printf("最大值为:%d\n", data2);
	}
}
int main(int argc, char *argv[])
{
	test05();

	return 0;
}
