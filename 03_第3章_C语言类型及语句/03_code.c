/* ************************************************************************
 *       Filename:  03_code.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2021年07月21日 16时10分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/


#include <stdio.h>
void test01()
{
	printf("%lu\n", sizeof(3.14));
	printf("%lu\n", sizeof(3.14f));
}
void test02()
{
	//=号两边类型必须匹配
	//float f=3.14;//3.14为double类型 而f为float类型 所以类型不匹配
	float f = 0.0f;

	printf("请输入一个浮点数:");
	scanf("%f", &f);
	
	printf("f = %f\n", f);

	double d = 0.0;
	printf("请输入一个浮点数:");
	scanf("%lf", &d);
	printf("d = %lf\n", d);
	
}
void test03()
{
	//
	int num = 123;
	printf("%#o\n", num);
	printf("%d\n", num);
	printf("%#x\n", num);
}
void test04()
{
	char ch1=-10;
	printf("ch1=%#x\n", ch1);

	char ch2=6;
	printf("ch2=%#x\n", ch2);

	
}
int main(int argc, char *argv[])
{
	test04();
	return 0;
}


