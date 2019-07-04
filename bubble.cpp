/*************************************************************************
    > File Name: main.cpp
    > Created Time: Mon 21 Jan 2019 11:45:22 AM CST
 ************************************************************************/

//冒泡排序
//平均时间O(n^2)
//最坏情况O(n^2)
//辅助存储O(1)

#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void bubble_sort(int *arr, int n)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	for(; i < n - 1; i++)
	{
		//从第一个元素依次往后比较，找出最大的一个
		for(j = 1; j < n - i; j++)
		{
			if(arr[j] < arr[j-1])
			{
				swap(arr[j], arr[j-1]);
				flag = 1;
			}
		}
		if(flag == 0)
			break;
	}
}

int main()
{

	int arr[] = {45,76,34,50,97,21,38,79,64,46,78,100,234};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr, n);
	
	int i = 0;
	for(; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}
