/*************************************************************************
    > File Name: main.cpp
    > Created Time: Mon 21 Jan 2019 07:30:54 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;


//快速排序
//平均时间O(nlongn)
//最坏时间O(n^2)
//辅助空间
//	递归O(logn)
//	非递归O(1)
//
//优化
//	1、三数取中做为枢轴
//	2、小规模用插排
//	3、取随机下标的值做为枢轴

int Partition(int *arr, int low, int high)
{
	int i = low;
	int j = high;
	int tmp = arr[low];
	while(i < j)
	{
		//从后往前，直到第一个比枢轴小的元素
		while(i < j&&arr[j] >= tmp)
			j--;
		//将其赋值给空余的位置（前半部分）
		if(i < j)
			arr[i] = arr[j];
		//从前往后， 知道第一个比枢轴大的元素
		while(i < j&& arr[i] < tmp)
			i++;
		//将其赋值给空余的位置（后半部分）
		if(i < j)
			arr[j] = arr[i];
	}
	arr[i] = tmp;
	return i;
}

//递归
void quick_sort_recursive(int *arr, int low, int high)
{
	if(low < high)
	{
		int pos = Partition(arr, low, high);
		quick_sort_recursive(arr, low, pos-1);
		quick_sort_recursive(arr, pos+1, high);
	}
}

//非递归
void quick_sort_nonrecursive(int *arr, int low, int high) 
{
	stack<int> sta;
	sta.push(low);//首先压入首元素和尾元素下标
	sta.push(high);
	while(!sta.empty())
	{
		//将栈顶的两个元素出栈，必须同时出栈（为一个要划分子序列的首尾下标）
		int j = sta.top();
		sta.pop();
		int i = sta.top();
		sta.pop();
		int pos = Partition(arr, i, j);
		//从pos的位置进行划分，前后两个子序列，一次入栈（首尾元素入栈顺序须一致）
		if(pos-i>1)
		{
			sta.push(i);
			sta.push(pos-1);
		}
		if(j-pos>1)
		{
			sta.push(pos+1);
			sta.push(j);
		}
	}
}

int main()
{
	int arr[] = {56,67,34,89,12,45,78,23,90,45};
	int len = sizeof(arr)/sizeof(arr[0]);

	quick_sort_nonrecursive(arr, 0, len-1);

	int i = 0;
	for(; i < len; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}
