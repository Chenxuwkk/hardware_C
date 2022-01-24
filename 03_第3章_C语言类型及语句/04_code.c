/* ************************************************************************
 *       Filename:  00_code.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2021年07月22日 08时49分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/


#include <stdio.h>
#if 0
void test01()
{
	//-10的无符号数 就是-10的补码
	unsigned char ch = 300;//1 0010 1100

	printf("%#x\n", ch);//0xfffffff6
	printf("%d\n", ch);//
	printf("%u\n", ch);//
}
void test02()
{
	//const修饰num为只读变量 本质是变量
	//只读变量 只能初始化 不能被赋值
	const int num = 100;
	num = 200;//error

}

void test03()
{
	//将num放入寄存器中 提高访问效率 num也叫寄存器变量
	register int num = 10;
	
	//不能对寄存器变量 取地址 &num是错误的
	&num;//&取的是内存地址 而num可能在寄存器中 所以取地址失败

	//register修饰的变量 只是尽量放入寄存器中

}
#endif
void test04()
{
	int num=0;
	printf("%lu\n", sizeof(num));
	printf("%lu\n", sizeof(int));

	printf("%lu\n", sizeof(short));
	printf("%lu\n", sizeof(long));
	char ch='a';
	printf("%lu\n", sizeof(ch));
	printf("%lu\n", sizeof('a'));


}
void test05()
{
	//INT32 是int的别名
	typedef int INT32;
	int num;//已有的类型任然有效
	INT32 data;//int data

}

void test06()
{
	typedef int MY_ARRAY[5];
	MY_ARRAY arr={1,2,3,4,5};
	int i=0;
	for(i=0;i<5;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	
}
void test07()
{
	printf("##%c##\n", '\n');
	printf("##%c##\n", '\t');
	printf("##%c##\n", '\r');
	printf("##%c##\n", '\a');
}
int main(int argc, char *argv[])
{
	test07();
	return 0;
}


