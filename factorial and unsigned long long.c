
这是一个计算阶乘的代码
阶乘函数fact
* 
* unsigned long long fact(int n); 
声明了一个名为 fact 的函数，它接受一个整数参数 n，
并返回一个无符号长长整数（unsigned long long），
以便处理较大的阶乘结果

#include <stdio.h>

// 函数声明：迭代计算阶乘
unsigned long long fact(int n);///这里代表可以返回一个很长很长的数字

int main() {
	int number;
	unsigned long long result;///////这个也是返回一个很长很长的数字

	while (1) {
		printf("请输入一个非负整数 (输入-1退出): ");
		if (scanf_s("%d", &number) != 1) {
			printf("输入无效，请输入一个整数。\n");
			// 清除输入缓冲区
			while (getchar() != '\n');
			continue;
		}

		if (number == -1) {
			printf("退出程序。\n");
			break;
		}

		if (number < 0) {
			printf("输入无效，请输入一个非负整数。\n");
			continue;
		}

		result = fact(number);
		printf("%d 的阶乘是 %llu\n", number, result);
	}

	return 0;
}
unsigned long long fact(int n) {
	unsigned long long result = 1;
	for (int i = 2; i <= n; i++) {
		result *= i;
		///这行代码的作用是将当前的 result 值乘以循环变量 i，
		///并将结果赋值回 result
	}
	return result;
}
