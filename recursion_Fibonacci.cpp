#include <iostream>
using namespace std;
int arr[100] = {0};                     //全局变量只能在定义时赋初值
int fib (int n, int arr[], int i)
{
    if (n <= 2)
    return 1;
    arr[i] = arr[i - 1] + arr[i - 2];
    if (i == n - 1)
    return arr[i];
    else
    fib (n, arr, i + 1);
}
int main()
{
    int n;
    cin >> n;
    arr[0] = arr[1] = 1;
    cout << fib (n, arr, 2);
    return 0;
} 
//建立数组后从前向后递归

 #include <iostream>
using namespace std;
int fib (int first, int second, int n)
{
    if (n <= 2)
    return 1;
    else if (n == 3)
    return first + second;
    fib (second, first + second, n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << fib (1, 1, n);
    return 0;
} 
//不建立数组从前向后递归