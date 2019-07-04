/*************************************************************************
    > File Name: main.cpp
    > Created Time: Mon 21 Jan 2019 12:00:33 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//选择排序
//平均时间O(n^2)
//最坏时间O(n^2)
//辅助存储O(1)


void swap(int &a, int &b)
{
	int tmp = a;
	a = b; 
	b = tmp;
}

int select_min(int *arr, int pos, int len)
{
	int i = pos+1;
	int rpos = pos;
	int tmp = arr[pos];
	for(; i < len; i++)
	{
		if(tmp > arr[i])
		{
			tmp = arr[i];
			rpos = i;
		}
	}
	return rpos;
}
void select_sort(int * arr, int len)
{
	int i = 0;
	for(; i < len; i++)
	{
		//选择一个最小的和当前值比较
		int pos = select_min(arr, i, len);
		if(pos != i)
		{
			swap(arr[pos], arr[i]);
		}
	}
}

int main()
{
	int arr[] = {65,13,24,99,75,49,21,48,57,90};
	int n = sizeof(arr)/sizeof(arr[0]);

	select_sort(arr, n);
	int i = 0;
	for(; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}
