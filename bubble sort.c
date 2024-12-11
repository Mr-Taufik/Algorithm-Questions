//冒泡排序
//这里的swapped用的很好，用于退出冒泡顺序循环
//对于有n个元素的数组，最多需要进行n-1趟遍历
//每进行一趟遍历，最大的未排序元素会“冒泡”到数组的末端，
//因此内层循环的范围会逐渐减少（n-i-1）
//swapped 初始化为0，表示这一趟遍历开始时还未发生交换




#include <stdio.h>

void bubbleSort(int arr[], int n);
void printArray(int arr[], int size);

int main()
{
	int arr[] = { 64, 34, 25, 12, 22 ,11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("排序前的数组：\n");
	printArray(arr, n);
	bubbleSort(arr, n);
	printf("排序后的数组：\n");
	printArray(arr, n);
	return 0;
}
void bubbleSort(int arr[], int n)
{
	int i, j;
	int temp;
	int swapped;

	for (i = 0; i < n - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[i] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
		printf("\n");
	}
}
