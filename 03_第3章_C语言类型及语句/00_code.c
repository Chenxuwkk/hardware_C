/* ************************************************************************
 *       Filename:  00_code.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2021年07月21日 10时02分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/

//这是行注释
/*
 这是块注释
 块注释不能嵌套
*/

//头文件 是对 库函数 进行声明
#include <stdio.h>//标准输入输出头文件

//main 就是主函数 一个工程有且只能有一个主函数
//main 是程序调用的入口
//main左边的int 为函数返回值类型 （）为函数的形参 
//形参：函数外部数据 传递到 函数内部 的桥梁
int main(int argc, char *argv[])
{//函数体
	//printf将()里面的字符串输出到 终端上
	printf("hello world\n");//分号;是结束语句

	//retrun 第一：返回值函数值   第二:结束当前函数
	return 0;
}



