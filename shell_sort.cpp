/*************************************************************************
    > File Name: main.cpp
    > Created Time: Tue 22 Jan 2019 12:59:00 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


//希尔排序 
//时间复杂度O(n^3/2)
//辅助存储O(1)


void shell_insert(int *arr, int len, int dk)
{
	int i = dk;
	int tmp = 0;
	for(; i < len; i++)
	{
		if(arr[i] < arr[i - dk])
		{
			tmp = arr[i];
			int j = i - dk;
			for(; j >= 0 && tmp < arr[j]; j -= dk)
			{
				arr[j + dk] = arr[j];
			}
			arr[j + dk] = tmp;
		}
	}
}

void shell_sort(int *arr,int *dlta, int len, int arrlen)
{
	int i = 0;
	for(; i < len; i++)
	{
		shell_insert(arr, arrlen, dlta[i]);
	}
}

int main()
{

	int arr[] = {49,38,65,97,76,13,27,49,55,4};
	int len = sizeof(arr)/sizeof(arr[0]);
	int dlta[] = {5, 3, 1};
	shell_sort(arr, dlta, 3, len);
	int i = 0;
	for(; i < len; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;

}
