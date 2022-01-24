/********************************************************
* Author       : Chenxuwkk 
* Last modified: 2022-01-23 13:11
* Email        : 1689204123@qq.com
* Filename     : 01_code.c
* Description  : My C program 
********************************************************/
#include<stdio.h>

void test01(){
		
		printf("This is a test01()\n");
		printf("%c\n",'a');
		printf("%s\n","hello world");

}





int main(){
		//volatile 防止编译器优化
		test01();
		return 0;




}
