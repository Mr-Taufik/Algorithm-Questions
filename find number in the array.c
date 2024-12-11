//查找数字


#include <stdio.h>

int main() {
	int array[] = { 2, 4, 6, 8, 10, 12, 14 };
	int size = sizeof(array) / sizeof(array[0]);
	int target;
	int index = 0;
	int found = 0;

	printf("请输入要查找的数字： ");
	scanf_s("%d", &target);

	while (index < size) { // 循环遍历数组
		if (array[index] == target) {
			printf("数字 %d 在数组中的位置是 %d（索引从0开始）。\n", target, index);
			found = 1;
			break; // 找到后退出循环
		}
		index++;
	}

	if (!found) {
		printf("数字 %d 不在数组中。\n", target);
	}

	return 0;
}
