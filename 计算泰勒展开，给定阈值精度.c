该程序输入x就可以开始计算x的n次方除于n的阶乘，一共有n项，通过控制给定的精度来结束循环

fabs表示一个数字的绝对值，这里是用来判断后面计算的项的精度
/////////计算级数和
//例如泰勒级数展开
//term *= x / n;
//x / n：表示将x除以当前的阶数n
//每一项term_n可以通过将前一项term_{ n - 1 }乘以x / n得到计算级数
///程序设计96页第2题


#include <stdio.h>
#include <math.h>

// 函数声明（可选）
double calculateSeries(double x, double threshold, int* termCount);

int main() {
	double x;
	double sum;
	int termCount = 0;
	double threshold = 0.00001;

	// 输入部分
	while (1) {
		printf("请输入一个正实数x: ");
		if (scanf_s("%lf", &x) != 1) {
			printf("输入无效，请输入一个数字。\n");
			while (getchar() != '\n'); // 清除输入缓冲区
			continue;
		}
		if (x <= 0) {
			printf("x必须是一个正实数，请重新输入。\n");
			continue;
		}
		break;
	}

	// 级数求和
	sum = calculateSeries(x, threshold, &termCount);

	// 输出结果
	printf("\n级数的和为: %.10f\n", sum);
	printf("共计算了 %d 项。\n", termCount);

	return 0;
}

// 计算级数的函数
double calculateSeries(double x, double threshold, int* termCount) {
	double sum = 1.0;       // 累加和，初始为1（对应x^0 / 0!）
	double term = 1.0;      // 当前项的值，初始为1（对应x^0 / 0!）
	int n = 1;              // 当前项的指数

	while (1) {
		term *= x / n;      // 计算下一项：term = term * x / n
		if (fabs(term) < threshold) {
			break;
		}
		sum += term;
		printf("第 %d 项: %.10f，当前和: %.10f\n", n, term, sum);
		n++;
	}

	*termCount = n - 1; // 已添加的项数
	return sum;
}
///计算ex的泰勒级数
//避免重复计算阶乘： 使用递推公式可以逐步计算每一项，无需重新计算阶乘。
//减少函数调用： 通过递推减少了对复杂数学函数的调用，提高了程序的执行效率
//使用 double 类型可以保证较高的计算精度，尤其是在处理较大的 x 值或需要高精度的计算时
//设定合理的终止条件 threshold(阈值) = 0.00001，确保在达到所需精度时程序停止运行，避免不必要的计算。
////////
/*int *termCount 的角色
在你提供的代码示例中，int *termCount 是一个指向整数的指针，
用于在函数内部记录和传递“使用了多少项”这一信息到调用函数。
calculateSeries 函数接收三个参数：
double x: 级数的基数。
double threshold: 终止条件的阈值。
int *termCount: 一个指向整数的指针，用于记录和传递使用的项数。
使用 &termCount 将其地址传递给 calculateSeries 函数，使得该函数可以修改 termCount 的值。
*termCount = n - 1; // 已添加的项数
*termCount 表示指针所指向的地址处存储的值（即 main 函数中的 termCount）。
通过赋值操作，calculateSeries 函数将计算过程中使用的项数传递回 main 函数
为什么使用指针而不是返回值？
额外结果通过指针参数传递： int *termCount 允许函数修改 main 中的 termCount 变量

C语言中的函数参数是按值传递的。这意味着，当你传递一个变量给函数时，函数会接收到该变量的一个拷贝。
对于基本类型（如 int, double），这通常足够。但是，如果你想要在函数内部修改外部变量的值，就需要使用指针（即传址）
