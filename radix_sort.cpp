/*************************************************************************
    > File Name: main.cpp
    > Created Time: Mon 21 Jan 2019 09:47:03 AM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

//基数排序（桶排序）
//平均时间O(d(n+rd)) => O(n)
//最坏时间O(d(n+rd)) => O(n)
//辅助存储O(rd)


int maxbit(int *arr, int n)
{
	int d = 1;
	int p = 10;
	int i = 0;
	for(; i < n; i++)
	{
		while(arr[i] >= p)//若有元素大于10，则表示有两位数存在，然后再比较三位数
		{
			p *= 10;
			d++;
		}
	}
	return d;
}

void radix_sort(int *arr, int n)
{
	int d = maxbit(arr, n);
	int tmp[n];//临时数组
	int count[10];//计数器，记录0-9每个下标的元素个数
	int i, j, k;
	int radix = 1;//用来求元素某位上数值
	for(i = 0; i < d; i++)
	{
		for(j = 0; j < 10; j++)//初始化计数器
		{
			count[j] = 0;
		}

		for(j = 0; j < n; j++)//计算每个下标上的元素个数
		{
			k = (arr[j]/radix)%10;
			count[k]++;
		}
		for(j = 1; j < 10; j++)//将每个下标与tmp中的下标对应起来
		{
			count[j] = count[j-1]+count[j];
		}
		for(j = n-1; j >= 0; j--)//赋值给临时数组
		{
			k = (arr[j]/radix)%10;
			tmp[count[k]-1] = arr[j];
			count[k]--;
		}
		for(j = 0; j < n; j++)//将临时数组中的值拷贝回arr
		{
			arr[j] = tmp[j];
		}
		radix = radix*10;//比较下一位
	}
}

int main()
{
	int arr[] = {34,12,76,36,98,60,54,33,20};
	int n = sizeof(arr)/sizeof(arr[0]);

	radix_sort(arr, n);
	int i = 0;
	for(; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
