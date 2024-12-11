这底下是两个不同的查找最小值的代码，分别都用了指针在void
自定义函数里面实现

#include <stdio.h>

// 函数声明
void findMaxMin(int arr[], int size, int* max, int* min);

int main()
{
    int arr[10];
    int max, min;

    printf("输入10个数字：\n");

    // 输入10个数字
    for (int i = 0; i < 10; i++)
    {
        if (scanf_s("%d", &arr[i]) != 1) 
        {
            printf("输入错误。\n");
            return 1;
        }
    }

    int size = sizeof(arr) / sizeof(arr[0]);

    // 初始化 max 和 min 为第一个元素
    max = arr[0];
    min = arr[0];

    // 调用函数查找最大值和最小值
    findMaxMin(arr, size, &max, &min);

    printf("The Max number is %d, Min number is %d\n", max, min);
    return 0;
}

void findMaxMin(int arr[], int size, int* max, int* min)
{
    for (int i = 1; i < size; i++)  // 从第二个元素开始
    {
        if (arr[i] > *max)
        {
            *max = arr[i];
        }

        if (arr[i] < *min)
        {
            *min = arr[i];
        }
    }
}




#include <stdio.h>

// 函数声明：查找最大值和最小值
void findMaxMin(int arr[], int size, int* max, int* min);

int main() 
{
    int numbers[] = { 23, 45, 12, 67, 34, 89, 2, 78 };
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int maximum, minimum;

    findMaxMin(numbers, size, &maximum, &minimum);

    printf("最大值 = %d, 最小值 = %d\n", maximum, minimum);

    return 0;
}

void findMaxMin(int arr[], int size, int* max, int* min) 
{
    if (size <= 0) {
        *max = *min = 0;
        return;
    }

    *max = *min = arr[0];

    for (int i = 1; i < size; i++) 
    {
        if (arr[i] > *max) 
        {
            *max = arr[i];
        }
        if (arr[i] < *min) 
        {
            *min = arr[i];
        }
    }
}
