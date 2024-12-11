这个程序用了while循环来计算奇数和，当输入不是数字的时候


#include <stdio.h>

int main()
{
	int number;
	int sum = 0;

	while (scanf_s(" %d", &number) != 0)//////当scnaf输入的时候输入的和%d不匹配就不会返回1，通常是-1
	{
		if (number % 2 != 0)
		{
			sum += number;
			printf("ÆæÊý%d, Ä¿Ç°×ÜºÍ%d\n", number, sum);
		}
	}
	return 0;
}
