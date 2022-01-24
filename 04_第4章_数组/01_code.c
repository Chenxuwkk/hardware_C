/* ************************************************************************
 *       Filename:  01_code.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2021年07月23日 15时44分04秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/


#include <stdio.h>
#include <string.h>
void test01()
{
	char arr1[]={'h','e','l','l','o'};
	char arr2[]="hello";

	//sizeof测量的是 数组空间总大小
	printf("sizeof(arr1)=%lu\n",sizeof(arr1));//5
	printf("sizeof(arr2)=%lu\n", sizeof(arr2));//6

	//strlen 测量的是字符串的长度（不计算'\0'）, 遇到'\0'结束长度计算
	printf("strlen(arr1)=%lu\n",strlen(arr1));//不确定 概述数组没有'\0'访问非法内存
	printf("strlen(arr2)=%lu\n",strlen(arr2));//5 

	char arr3[]="hello\0world";
	printf("sizeof(arr3)=%lu\n",sizeof(arr3));//12
	printf("strlen(arr3)=%lu\n",strlen(arr3));//5 

	// 两个反斜杠 算一个字符
	char arr4[]="\123456\xab\\\abc";
	printf("sizeof(arr4)=%lu\n",sizeof(arr4));//10
	printf("strlen(arr4)=%lu\n",strlen(arr4));//9 
	
}
void test02()
{
	char str[128]="";//推荐的方式

	printf("请输入一个字符串:");
	fgets(str, sizeof(str), stdin);
	str[strlen(str)-1]=0;//消除获取到的回车

	printf("输出结果:##%s##\n", str);
}
void test03()
{
	char str1[128]="";
	char str2[128]="";

	printf("请输入一个字符串:");
	fgets(str1,sizeof(str1),stdin);
	str1[strlen(str1)-1] = 0;

	//字符串拷贝
	int i=0;
	while(str1[i] != '\0')
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i]='\0';
		
	printf("str2=##%s##\n", str2);
}
void test04()
{
	char str1[128]="hello";
	char str2[128]="world";

	//将i定位到尾部
	int i=0;
	while(str1[i] && ++i);

	//将str2的每个元素 复制到 str1的尾部
	int j=0;
	while(str2[j] != '\0')
	{
		str1[i] = str2[j];
		i++;
		j++;
	}
	str1[i]='\0';

	printf("##%s##\n", str1);
}
void test05()
{
	char str[128]="";
	
	printf("亲输入一个字符串:");
	fgets(str,sizeof(str),stdin);
	str[strlen(str)-1]=0;

	char ch='\0';
	printf("请输入要查找的字符:");
	ch = getchar();

	//开始查找
	int i=0;
	while(str[i] != '\0')
	{
		if(str[i] == ch)
		{
			printf("找到位置为:%d\n", i);
			break;
		}
		i++;
	}

	if(str[i] == '\0')
	{
		printf("没有找到\n");
	}
}

void test06()
{

	char str1[128]="";	
	printf("亲输入一个字符串:");
	fgets(str1,sizeof(str1),stdin);
	str1[strlen(str1)-1]=0;
	
	char str2[128]="";
	printf("亲输入第二个字符串:");
	fgets(str2,sizeof(str2),stdin);
	str2[strlen(str2)-1]=0;

	int pos=0;
	printf("请输入要插入的位置:");
	scanf("%d", &pos);

	//计算str2的长度
	int len = 0;
	while(str2[len] && ++len);

	//将i定位到str1的尾部  i也是str1的长度
	int i=0;
	while(str1[i] && ++i);

	//判断pos位置是否 合法
	if(pos<0 || pos>i)
	{
		printf("下标%d不无效\n", pos);
		return;//结束函数
	}

	//数据是否溢出
	if(i+len>sizeof(str1))
	{
		printf("插入会越界，失败\n");
		return;//结束函数
	}

	//在str1移动数据 预留足够的位置
	while(i>=pos)
	{
		str1[i+len] = str1[i];
		i--;
	}

	//将str2的字符串 插入到pos位置上
	int j=0;
	while(str2[j] != '\0')
	{
		str1[pos] = str2[j];
		pos++;
		j++;
	}


	printf("插入后的结果：%s\n", str1);
}
int main(int argc, char *argv[])
{
	test06();
	return 0;
}


