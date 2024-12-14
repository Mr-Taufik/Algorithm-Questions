#include <stdio.h>

int main()
{
	int a, n;
	int sum = 0;

	// 读取初始值和项数
	printf("请输入一个整数 a: ");
	scanf_s("%d", &a);
	printf("请输入项数 n: ");
	scanf_s("%d", &n);

	int term = a; // 用于存储当前项的变量，初始为 a

	for (int i = 1; i <= n; i++)
	{
		sum += term;          // 将当前项加到总和中
		term = term * 10 + a; // 生成下一项，例如 a=2 时，2 -> 22 -> 222
	}

	printf("总和为: %d\n", sum);
	return 0;
