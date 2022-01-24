/* ************************************************************************
 *       Filename:  00_code.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2021年07月23日 09时40分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/


#include <stdio.h>
void test01()
{
	int arr[5];
	int n = sizeof(arr)/sizeof(arr[0]);

	printf("数组的总大小=%lu\n", sizeof(arr));
	printf("数组元素大小=%lu\n", sizeof(arr[0]));
	printf("数组元素的个数=%lu\n", sizeof(arr)/sizeof(arr[0]));

	int i=0;
	for(i=0;i<n;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}
void test02()
{
	int arr[5]={[2]=10, [4]=30};
	int n = sizeof(arr)/sizeof(arr[0]);

	int i=0;
	for(i=0;i<n;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}
void test03()
{
	int arr[5]={0};
	int n = sizeof(arr)/sizeof(arr[0]);

	//num取值
	printf("%d\n", arr[2]);

	//num赋值 num=10
	arr[2]=10;
	
	//data = num
	arr[3] = arr[2];

	//num++
	arr[3]++;//arr[3] = arr[3]+1

	int i=0;
	for(i=0;i<n;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test04()
{
	int arr[5] = {0};
	int n = sizeof(arr)/sizeof(arr[0]);

	printf("请输入%d个int数据:", n);
	int i=0;
	for(i=0;i<n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for(i=0;i<n;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test05()
{
	int arr[10]={0};
	int n = sizeof(arr)/sizeof(arr[0]);

	printf("请输入%d个int数据:", n);
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}

	//选择法排序
	int s= 0;
	for(s=0;s<n-1; s++)
	{
		int min = s;
		int j = min+1;
		for(; j<n; j++)
		{
			if(arr[min] > arr[j])//从小--->大
			{
				min = j;//纪录最小值的下标
			}
		}

		//判断假设的最小值下标 和 真实的最小值下标是否 相等 如果不相等 交换
		if(s != min)
		{
			int tmp = arr[s];
			arr[s] = arr[min];
			arr[min] = tmp;
		}
	}


	for(i=0;i<n;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}
void test06()
{
	int arr[3][4]={0};
	int row = sizeof(arr)/sizeof(arr[0]);
	int col = sizeof(arr[0])/sizeof(arr[0][0]);

	printf("请输入%d个int数据\n", row*col);
	int i=0,j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

}
void test07()
{
	int arr[5][4]={{56,75,78,89},{89,98,76,67},{88,99,77,66},{67,78,89,90},{98,97,96,95}};
	int row = sizeof(arr)/sizeof(arr[0]);
	int col = sizeof(arr[0])/sizeof(arr[0][0]);
	//定义一个一维数组 存放学科的平均成绩
	int avg[4]={0};
	
	int j = 0;
	for(j=0;j<col;j++)
	{
		int i=0,sum=0;
		for(i=0;i<row;i++)
		{
			sum += arr[i][j];
		}
		avg[j] = sum/row;

	}

	int i=0;
	for(i=0;i<col;i++)
	{
		printf("%d ", avg[i]);
	}
	printf("\n");
}
int main(int argc, char *argv[])
{
	test07();
	return 0;
}


