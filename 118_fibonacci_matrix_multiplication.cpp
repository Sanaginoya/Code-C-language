//对于这道题优化算法的方式似乎只是单纯优化计算方法
#include <iostream>
using namespace std;
int Temp[2][2] = {{1, 1}, {1, 0}};
int ding[2][2] = {{1, 1}, {1, 0}};
int mod (int a)
{
    return (a % 10000);
}
void matrix_multiplication (int a[2][2], int b[2][2])
{
        int temp[2][2];
        temp[0][0] = mod(a[0][0]) * mod(b[0][0]) + mod(a[0][1]) * mod(b[1][0]);
        temp[0][1] = mod(a[0][0]) * mod(b[0][1]) + mod(a[0][1]) * mod(b[1][1]);
        temp[1][0] = mod(a[1][0]) * mod(b[0][0]) + mod(a[1][1]) * mod(b[1][0]);
        temp[1][1] = mod(a[1][0]) * mod(b[0][1]) + mod(a[1][1]) * mod(b[1][1]);
        for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        Temp[i][j] = mod(temp[i][j]);
        return;
}
void divide2 (int n)
{
    if (n % 2 == 0)
    {
        divide2(n / 2);
        matrix_multiplication(Temp, Temp);
    }
    else if ((n % 2 != 0) && (n != 1))
    {
        divide2(n / 2);
        matrix_multiplication(Temp, Temp);
        matrix_multiplication(Temp, ding);
    }
    else if (n == 1)
    return;
}
int main()
{
    int n;
    cin >> n;
    if (n != 0){
    divide2(n);
    cout << Temp[0][1];
    }
    else
    cout << "0";
    return 0;
}