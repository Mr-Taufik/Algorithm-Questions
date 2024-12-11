这个代码，输入一个整数可以计算前n项的数字的平方根之和
还加入了//while语句用于循环输入错误的重新输入




#include <stdio.h>
#include <math.h>
#include <stdlib.h> // 用于 system("pause")

double calculateSquareRootSum(int N);

int main()
{
	int N;
	double sum = 0.0;

	while (1) {
		printf("请输入一个大于1的整数N： ");
		if (scanf_s("%d", &N) != 1) {
			// 如果输入不是整数，清除输入缓冲区
			printf("输入无效，请输入一个整数。\n");
			while (getchar() != '\n'); // 清除缓冲区
			continue;
			//在检测到无效输入后，使用
			// while (getchar() != '\n'); 清除输入缓冲区，以防止无限循环
		}//这是一个无限循环的while循环，需要手动退出
		if (N > 1) {
			break; // 有效输入，退出循环
		}
		printf("N 必须大于1，请重新输入。\n");
	}
	sum = calculateSquareRootSum(N);

	printf("前%d项的平方根之和等于 %.6lf\n", N, sum);

	// 暂停控制台，以便查看结果
	 system("pause"); // 仅适用于Windows。如果不想使用system("pause")，可以使用以下替代方法：
	// printf("按回车键退出...");
	// getchar(); // 读取上一个输入留下的换行符
	// getchar(); // 等待用户按回车

	return 0;
}

double calculateSquareRootSum(int N)
{
	double sum = 0.0;
	for (int i = 1; i <= N; i++)
	{
		sum += sqrt((double)i);
	}
	return sum;
}
