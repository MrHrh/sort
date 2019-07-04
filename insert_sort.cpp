/*************************************************************************
    > File Name: main.cpp
    > Created Time: Tue 22 Jan 2019 12:07:11 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//直接插入排序
//最好时间复杂度O(n)
//最坏时间复杂度O(n^2)
//平均复杂度O(n^2)
//辅助存储O(1)
//
//优化：先进行大小判断，再进入二层循环

void insert_sort(int *arr, int len)
{
	int i = 0;
	for(; i < len-1; i++)
	{
		//从要插入的元素的下标依次往前找，新元素小则将旧元素后移，否则退出
		if(arr[i] > arr[i+1])
		{
			int j = i+1;
			int tmp = arr[j];
			for(; (j > 0) && (tmp < arr[j-1]); j--)
			{
				arr[j] = arr[j-1];
			}
			arr[j] = tmp;//将新元素插入正确的位置
		}
	}
}

int main()
{

	int arr[] = {45,76,34,31,23,89,70,66,78,100};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	insert_sort(arr, len);
	int i = 0;
	for(; i < len; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
