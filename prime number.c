通过一个标志变量 isPrime 来记录是否找到因子，只有在所有可能的因子都检查完毕后，才决定是否为素数
确保数字 2 被正确识别为素数
数字 1 和小于 1 的数字：根据定义，1 和小于 1 的数字不是素数
数字 2：作为最小的素数，程序误判为非素数。

#include <stdio.h>
#include <math.h>

int main()
{
    int number;
    printf("请输入一个整数: ");
    while (1)
    {
        if (scanf_s("%d", &number) != 1)
        {
            printf("输入无效，请重新输入\n");
            while (getchar() != '\n'); // 清除输入缓冲区
            printf("请输入一个整数: ");
            continue;
        }
        else
        {
            break;
        }
    }

    if (number <= 1)
    {
        printf("该数字不是素数\n");
        return 0;
    }

    int isPrime = 1; // 假设是素数
    int limit = (int)sqrt((double)number);
   //这里的limit就是素数的一种计算方法，开平方
    for (int i = 2; i <= limit; i++)
    {
        if (number % i == 0)
        {
            isPrime = 0; // 找到一个因子，不是素数
            break;
        }
    }

    if (isPrime)
    {
        printf("该数字是素数\n");
    }
    else
    {
        printf("该数字不是素数\n");
    }

    return 0;
}
