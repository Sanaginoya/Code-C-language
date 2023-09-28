#include <stdio.h>

int main() {
    double num1, num2, sum;

    // 输入两个数
    printf("请输入两个数: ");
    scanf("%lf %lf", &num1, &num2);

    // 计算两个数的和
    sum = num1 + num2;

    // 输出结果
    printf("两个数的和是: %.2lf\n", sum);

    return 0;
}