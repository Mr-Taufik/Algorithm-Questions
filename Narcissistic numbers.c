///这个代码可用用来计算3到7位数的水仙花数字
//输入位数然后会自动计算



#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	int a, b;
	printf("输入一个整数n 3<=n<=7: ");
	scanf_s("%d", &n);
////这里比较蠢是手动固定了循环的范围，为下面循环做了准备
	switch (n)
	{
	case 3:
		a = 100;
		b = 999;
		break;
	case 4:
		a = 1000;
		b = 9999;
		break;
	case 5 :
		a = 10000;
		b = 99999;
		break;
	case 6 :
		a = 100000;
		b = 999999;
		break;
	case 7:
		a = 1000000;
		b = 9999999;
		break;
	}

	int arr[8];
	////创立一个数组用来储存水仙花数的每一位数字

	for (int i = a; i <= b; i++)
	{
		int temp = i;
		////这行的意思是让下一个for循环的数字等于我们需要判断的水仙花数字
		
		for (int j = 0; j < n; j++)
		{
			arr[j] = temp % 10;///这里是用来余数计算需要求的数字里面的每一位数字，用数组来储存
			temp = temp / 10;
		}
		int sum = 0;
		for (int z = 0; z < n; z++)
		{
			sum += pow(arr[z], n);////这里是用来计算的，计算每一位数字的对应的次方和
		}
		if (sum == i)//这里是用来判断是否为水仙花的
		{
			printf("%d是水仙花数\n", i)；
		}
		
	}

	return 0;
}

//////////////
/////水仙花数
/////
/*
#include <stdio.h>
#include <math.h>

// 函数：计算数字的位数
int countDigits(int number);

// 函数：计算一个数的水仙花数之和
int calculateSumOfPowers(int number, int power);
	

int main() {
	int lower, upper;

	printf("请输入检查水仙花数的范围。\n");
	printf("最低数字：");
	if (scanf("%d", &lower) != 1 || lower < 0) {
		printf("输入无效，请输入一个非负整数。\n");
		return 1;
	}

	printf("最高数字：");
	if (scanf("%d", &upper) != 1 || upper < lower) {
		printf("输入无效，请输入一个大于或等于最低数字的整数。\n");
		return 1;
	}

	printf("范围 [%d, %d] 内的水仙花数有：\n", lower, upper);
	int found = 0;
	for (int number = lower; number <= upper; number++) {
		int digits = countDigits(number);
		int sum = calculateSumOfPowers(number, digits);
		if (sum == number) {
			printf("%d\n", number);
			found = 1;
		}
	}

	if (!found) {
		printf("在范围 [%d, %d] 内没有找到水仙花数。\n", lower, upper);
	}

	return 0;
}

int countDigits(int number)
{
	if (number == 0)
		return 1;
	int count = 0;
	while (number != 0) {
		number /= 10;
		count++;
	}
	return count;
}
int calculateSumOfPowers(int number, int power) 
{
	int sum = 0;
	int temp = number;
	while (temp != 0) {
		int digit = temp % 10;
		sum += pow(digit, power);
		temp /= 10;
	}
	return sum;
}

另外一种方法
#include <stdio.h>
#include <math.h>

int main()
{
	int n = 100;
	while (n < 9999999)
	{
		int count = 0;
		int sum = 0;
		//scanf_s("%d", &n);
		int a = 1;
		while (1)
		{
			if (n / a == 0)
				break;
			a *= 10;
			count++;
		}
		int n1 = n;
		for (int i = 0; i < count; i++)
		{
			int cur = n1 % 10;
			sum += pow(cur, count);
			n1 /= 10;
		}

		if (sum == n)
			printf("水仙花 %d\n",sum);

		n++;
	}

	return 0;
}



