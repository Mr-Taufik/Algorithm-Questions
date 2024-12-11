使用sizeof计算需要循环的次数
计算average的时候，由于都是整数，所以需要改变类型
改为float

#include <stdio.h>

int main()
{
	int numbers[4] = { 55, 22, 11, 33 };
	int sum = 0;
	float average;

	for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
	{
		sum += numbers[i];
	}

	average = (float)sum / (sizeof(numbers) / sizeof(numbers[0]));

	printf("sum: %d\naverage: %f", sum, average);
	return 0;

}
