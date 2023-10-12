#include <stdio.h>
#include <math.h>

int main() {
    double angle_degrees;
    
    // 输入角度（以度为单位）
    printf("请输入角度（以度为单位）: ");
    scanf("%lf", &angle_degrees);

    // 将角度转换为弧度
    double angle_radians = angle_degrees * (M_PI / 180.0);

    // 计算正弦、余弦和正切值
    double sine_value = sin(angle_radians);
    double cosine_value = cos(angle_radians);
    double tangent_value = tan(angle_radians);

    // 输出结果
    printf("正弦值: %.4lf\n", sine_value);
    printf("余弦值: %.4lf\n", cosine_value);
    printf("正切值: %.4lf\n", tangent_value);

    return 0;
}
