利用e的泰勒展开计算e的值



#include <stdio.h>

int main()
{
	double e = 1;
	double sum = 0;
	double factorial = 1.0;
	int n;
	printf(" Enter a number n : \n");
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		factorial *= i;
		sum += 1.0 / factorial;
	}

	e += sum;
	printf("e = %.15lf", e);///%lf 默认只会显示小数点后六位
	/////double 类型在大多数系统上提供大约 15-17 位十进制有效数字的精度
	/////
	return 0;
}
