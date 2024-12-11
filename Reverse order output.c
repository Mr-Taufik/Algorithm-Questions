
//逆序输出

#include <stdio.h>


int main()
{
	int numbers;
	printf("输入一个数字： ");
	scanf_s("%d", &numbers);
	do
	{
		printf("%d ", numbers % 10);//这里是计算numbers除于10的余数
		numbers = numbers / 10;//整数除法会向下取整（也就是丢弃小数部分），即使结果是负数，也会向下取整到最接近的整数

	} while (numbers % 10 != 0);//这里当numbers除于10不是零的时候循环上面的程序；
	return 0;
}

