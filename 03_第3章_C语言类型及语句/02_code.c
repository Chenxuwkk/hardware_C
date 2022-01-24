/* ************************************************************************
 *       Filename:  02_code.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2021年07月21日 15时13分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/


#include <stdio.h>
void test01()
{
	printf("%c\n", '\0');
	printf("%d\n", '\0');
}

void test02()
{
	char ch='\0';

	printf("请输第一个字符:");
	//获取字符的第一种方式：scanf  %c
	//%c只能提取一个字符
	scanf("%c", &ch);
	//去掉输入的回车
	getchar();

	printf("ch = %c\n", ch);
	printf("ch = %d\n", ch);

	//getchar 获取字符
	printf("请输第二个字符:");
	ch = getchar();
	printf("ch = %c\n", ch);
	printf("ch = %d\n", ch);
}
void test03()
{
	char ch='\0';

	printf("请输入一个字符:");
	ch = getchar();

	if(ch>='a' && ch<='z')
	{
		//ch = ch -('a'-'A');
		ch -= ('a'-'A');
	}
	else if(ch>='A' && ch<='Z')
	{
		//ch = ch +('a'-'A');
		ch += ('a'-'A');
	}

	printf("转换后的结果:%c\n", ch);
}
int main(int argc, char *argv[])
{
	test03();
	return 0;
}


