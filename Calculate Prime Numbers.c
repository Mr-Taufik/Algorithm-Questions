参数类型：sqrt 函数接受一个 double 类型的参数。
返回值类型：sqrt 函数返回一个 double 类型的值。
这意味着，如果传递给 sqrt 函数的参数是整数类型（如 int），C 编译器会根据类型转换规则，
隐式地将整数类型转换为 double，以满足函数的参数要求
提高代码可读性：通过显式的 (double) 转换，可以明确告诉代码阅读者，
你是有意将 num 视为浮点数类型进行平方根计算，而非无意的隐式转换。
sqrt 函数返回的是一个浮点数（double），而这里的代码需要整数类型的结果来用于循环的边界条件
编译器会隐式地将 num 转换为 double。虽然在大多数情况下这不会引起错误，
但代码的意图不够明确，并可能引发某些编译器的警告



#include <stdio.h>
#include <math.h>

int isPrime(int num) 
{
	if (num < 2)
                    return 0;	 // 0 和 1 不是素数
	int max_divisor = (int)sqrt((double)num);
	for (int i = 2; i <= max_divisor; i++) 
	{
		if (num % i == 0)
			return 0; // 找到因子，非素数
	}
	return 1; // 无因子，素数
	///确保只有在所有可能的j都不整除i时，才将i判定为素数
}

int main()
{
	int count = 0;
	printf("打印200 - 300 之间的素数\n");

	for (int i = 200; i <= 300; i++)
	{
		if (isPrime(i))
		{
			printf("%d ", i);
			count++;
		}
	}

	printf("\n素数的总数量: %d\n", count);
	return 0;
}
