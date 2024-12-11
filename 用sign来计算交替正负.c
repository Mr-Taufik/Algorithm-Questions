#include <stdio.h>

int main()
{
	int sign = 1;
	int sum = 0;

	// 从 1 开始到 101，步长为 2
	for (int i = 1; i <= 101; i += 2)
	{
		sum += i * sign; // 根据符号进行加减
		sign = -sign;    // 每次符号交替
	}

	printf("plus number: %d\n", sum);
	return 0;
}
