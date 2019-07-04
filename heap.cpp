/*************************************************************************
    > File Name: main.cpp
    > Created Time: Tue 22 Jan 2019 04:06:58 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


//最小堆排序
//时间复杂度O(nlogn)
//辅助空间O(1)
//


void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void heap_adjust(int *arr, int start, int end)
{
	int i = start;//当前节点下标
	int j = 2 * i + 1;//当前孩子节点
	int tmp = arr[i];

	while(j <= end)
	{
		if(j < end && arr[j] > arr[j+1])//将j换到左右孩子中值较大的一个
			j = j + 1;
		if(tmp < arr[j])//和双亲节点比较，若比双亲小，则换，否则退出
			break;
		arr[i] = arr[j];
		i = j;
		j = 2 * i + 1;
	}
	arr[i] = tmp;
}

void make_heap(int *arr, int len)
{
	int end = len - 1;
	int pos = (end - 1)/2;
	while(pos >= 0)
	{
		heap_adjust(arr, pos, end);
		pos--;
	}
}

void heap_sort(int *arr, int len)
{
	int end = len - 1;
	while(end > 0)
	{
		swap(arr[end], arr[0]);
		make_heap(arr, end);
		end -= 1;
	}
}

int main()
{
	int arr[] = {34, 667, 12, 16, 35, 90, 5, 87, 94, 69};
	int len = sizeof(arr)/sizeof(arr[0]);

	make_heap(arr, len);
	heap_sort(arr, len);

	int i = 0;
	for(; i < len; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}
