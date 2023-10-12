#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;     //一定要先输入再用变量定义数组
    int a[n];
    int i = 0;
    int sum = 0;   //养成初始化的好习惯
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i1 = 0, i2 = 0, i3 = 0;
    int temp;
    for (i1 = 0; i1 < n; i1++)   //最好不要直接应用循环参量
    {
        temp = abs(a[i1] - a[0]);
        for(i2 = 0; i2 < i1; i2++)
        {
            if (abs(a[i1] - a[i2]) < temp)
            temp = abs(a[i1] - a[i2]);
        }
        sum += temp;
    }
    sum += a[0];
    cout << sum;
    return 0;
}