代码计算任意输入两个数，他们中间数的平方和
还有他们的倒数和

#include <stdio.h>

int main()
{
    int a, b;
    int lower, upper;
    float sum_of_squares = 0.0f;
    float sum_of_reciprocals = 0.0f;
    float total_result = 0.0f;

    // 输入第一个数
    printf("Enter the first number: ");
    if (scanf_s("%d", &a) != 1) {///这里的写法是如果scanf输入是失败的就不会返回1， scanf输入成功的返回值是1
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    // 输入第二个数
    printf("Enter the second number: ");
    if (scanf_s("%d", &b) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    // 确定较小和较大的数
    if (a > b)
    {
        upper = a;
        lower = b;
    }
    else
    {
        upper = b;
        lower = a;
    }

    // 检查是否有有效的范围
    if (lower <= 0) {
        printf("The range must consist of positive integers to calculate reciprocals.\n");
        return 1;
    }

    // 计算平方和和倒数和
    for (int i = lower; i <= upper; i++)
    {
        sum_of_squares += (float)(i * i);
        sum_of_reciprocals += 1.0f / i;
    }

    // 计算总结果
    total_result = sum_of_squares + sum_of_reciprocals;

    // 输出结果
    printf("The sum of squares is: %.2f\n", sum_of_squares);
    printf("The sum of reciprocals is: %.2f\n", sum_of_reciprocals);
    printf("The total result (sum of squares + sum of reciprocals) is: %.2f\n", total_result);

    return 0;
}
