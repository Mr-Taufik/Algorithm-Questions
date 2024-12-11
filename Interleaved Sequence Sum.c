这个代码计算了一个交错序列的和
输入项数自动计算
该项目运用到了三元运算符
1-2/3+3/5-4/7+5/9.。。。。

#include <stdio.h>
#include <math.h>

// 函数声明：计算交错序列前n项的和
double calculateAlternatingSum(int n);

int main() {
	int n;
	double sum;

	printf("请输入要计算的项数 n: ");
	if (scanf_s("%d", &n) != 1 || n <= 0) {/////scanf_s 返回成功读取的项数。如果成功读取一个整数，
		/////返回值为 1。如果读取失败（例如用户输入了非整数值），返回值会小于 1
		printf("请输入一个正整数。\n");
		return 1;//这里的写法只能检查输入错误一次，并且会因为return1会退出当前的程序
	}

	sum = calculateAlternatingSum(n);

	printf("交错序列前 %d 项的和为: %.6f\n", n, sum);

	return 0;
}

double calculateAlternatingSum(int n) {
	double sum = 0.0;
	int k;
	double term;
	int sign;

	for (k = 1; k <= n; k++) {
		// 计算符号：奇数项为正，偶数项为负
		sign = (k % 2 == 1) ? 1 : -1;
		//三元运算符
		//语法格式：条件 ? 值1 : 值2
		//如果 条件 为 真，整个表达式的结果是 值1；如果 条件 为 假，结果是 值2

		//检查 k 是否为奇数：

		//k % 2 == 1 会返回 真 如果 k 是奇数，返回 假 如果 k 是偶数。
			//根据 k 的奇偶性赋值给 sign：

			//如果 k 是奇数(k % 2 == 1 为 真)，则 sign 被赋值为 1。
			//如果 k 是偶数(k % 2 == 1 为 假)，则 sign 被赋值为 - 1
		// 计算当前项
		term = sign * ((double)k / (2.0 * k - 1.0));

		// 累加到总和
		sum += term;
	}

	return sum;
}
