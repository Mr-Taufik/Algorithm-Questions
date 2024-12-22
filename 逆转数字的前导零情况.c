#include <stdio.h>
#define MAX 10




int main()
{
	int array[MAX] = { 0 };
	int number;
	int time = 0;
	printf("输入数字，这个数字不要超过十位数：");
	scanf_s("%d", &number);

	int arrayNumber = number;
	while (arrayNumber != 0)
	{
		
		array[time] = arrayNumber % 10;
		arrayNumber /= 10;

		time++;
	}

	time--;
	
	int leading_zero = 1;
	for (int i = 0; i <= time; i++)
	{
		if (array[i] == 0 && leading_zero)
		{
			continue;
		}
		leading_zero = 0;

		printf("%d", array[i]);
	}

	return 0;
}
