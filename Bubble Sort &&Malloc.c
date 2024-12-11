//高级一点的冒泡程序，可以自动
//语法：void* malloc(size_t size);
//malloc 是 C 标准库中的一个函数，用于在堆（heap）上分配一块指定大小的连续内存空间

#include <stdio.h>
#include <stdlib.h>

// 冒泡排序函数
void bubbleSort(int arr[], int size);
int main()
{
  setbuf(stdout, NULL);
	int N;

	// 输入循环，确保用户输入有效的N > 1
	while (1)
	{
		printf("请输入要输入的整数个数（大于1）： ");
		if (scanf("%d", &N) != 1)//这里是复合了语句，如果输入成功scanf是会返回值为1的
		{
			printf("输入无效，请输入一个整数。\n");
			// 清除输入缓冲区
			while (getchar() != '\n');//万金油
			continue;//结束这次循环
		}
		if (N > 1)
		{
			break;
		}
		printf("N 必须大于1，请重新输入。\n");
	}

	// 动态分配数组

	int* numbers = (int*)malloc(N * sizeof(int));
	
	//这里就是分配内存了
	//为numbers数组分配了N个位置储存数据
	//N * sizeof(int) 作用：计算需要分配的总字节数
	//解释：如果你需要存储 N 个整数，那么总共需要 N 乘以每个整数所占的字节数
	//int* numbers 作用：声明一个指向整数的指针 numbers，用于存储 malloc 分配的内存地址
	//这样，numbers 就可以像普通数组一样，通过指针操作来访问和操作这块内存
	
	if (numbers == NULL)
	{
		printf("内存分配失败。\n");
		return 1;
	}

	// 输入N个整数
	printf("请输入 %d 个整数：\n", N);
	for (int i = 0; i < N; i++)
	{
		while (1)
		{
			if (scanf_s("%d", &numbers[i]) != 1)
			{
				printf("输入无效，请输入一个整数。\n");
				// 清除输入缓冲区
				while (getchar() != '\n');
				continue;
			}
			break;
		}
	}

	// 排序
	bubbleSort(numbers, N);

	// 输出排序后的结果
	printf("排序后的结果是：");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", numbers[i]);
	}
	printf("\n");

	// 释放动态分配的内存
	free(numbers);

	return 0;
}
void bubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// 交换 arr[j] 和 arr[j + 1]
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
