/* ************************************************************************
 *       Filename:  02_code.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2021年07月22日 17时35分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/


#include <stdio.h>
void test01()
{
	int num = 0;

	printf("请输入一个int数据:");
	scanf("%d", &num);

	if(num%3 == 0)
	{
		printf("%d对3余数为0\n", num);
	}
	else if(num%3 ==0)
	{
		printf("%d对3的余数为1\n", num);

	}
	else if(num%3 == 2)
	{
		printf("%d对3的余数为2\n", num);

	}
}


#include <termios.h>
#include <stdio.h>
#include <unistd.h>
char mygetch( ) 
{    
	struct termios oldt, newt;    
	char ch;    
	tcgetattr( STDIN_FILENO, &oldt );    
	newt = oldt;    
	newt.c_lflag &= ~( ICANON | ECHO );    
	tcsetattr( STDIN_FILENO, TCSANOW, &newt );    
	ch = getchar();    
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );    
	return ch;
}
void test02()
{
	char ch='\0';

	ch = mygetch();

	switch(ch)
	{
		case 'q':
		case 'Q':
			printf("天音波\n");
			break;
		case 'w':
		case 'W':
			printf("铁布衫\n");
			break;
	}
}
void test03()
{
	int i=0;
	int sum=0;

	for(i=99; i>0; i=i-2)
	{
		sum = sum +i;
	}
	printf("sum = %d\n", sum);
}

void test04()
{
	int i=6;
	for(i=1;i<=9; i++)
	{
		int j = 0;
		//内层循环
		for(j=1; j<=i;j++)
		{
			printf("%d*%d=%d ",j,i,j*i );
		}
		printf("\n");

	}
}
void test05()
{
	printf("--------001----------\n");
	printf("--------002----------\n");
	goto here; 
	printf("--------003----------\n");
	printf("--------004----------\n");
here:
	printf("--------005----------\n");
	printf("--------006----------\n");
}
int main(int argc, char *argv[])
{
	test05();
	return 0;
}


