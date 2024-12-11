//冒泡排序
//这里的swapped用的很好，用于退出冒泡顺序循环
//对于有n个元素的数组，最多需要进行n-1趟遍历
//每进行一趟遍历，最大的未排序元素会“冒泡”到数组的末端，
//因此内层循环的范围会逐渐减少（n-i-1）
//swapped 初始化为0，表示这一趟遍历开始时还未发生交换




#include <stdio.h>
//这里定义了两个不返回的函数，接受两个参数，接收数组和长度
void bubbleSort(int arr[], int n);
void printArray(int arr[], int size);
//这里定义数组的时候还可以用
// void bubbleSort(int *arr, int n);
// void printArray(int *arr, int size);
//在C语言中，数组名在大多数表达式中会退化为指向其第一个元素的指针。
//因此，您只需要传递 arr 或 &arr[0] 即可，它们都是 int * 类型，符合函数的参数要求。
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

	for (i = 0; i < n - 1; i++)  //这里是外层循环，n个数字排序外层需要排序n-1次
	{
		swapped = 0;

		for (j = 0; j < n - i - 1; j++)//这里是内层循环，n个数字内层循环的次数是n-1-i次
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
		}
		if (swapped == 0)//swapped 变量在这段代码中用于提前退出循环
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
