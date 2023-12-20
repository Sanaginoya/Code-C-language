#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long sum = d / a;
    int bottle = sum, cap = sum;
    int temp1 = 0, temp2 = 0;
    while ((bottle >= b) || (cap >= c))
    {
        temp1 = bottle / b;
        temp2 = cap / c;
        sum = sum + temp1 + temp2;
        bottle = bottle - temp1 * b + temp1 + temp2;
        cap = cap - temp2 * c + temp1 + temp2;
    }
    cout << sum;
    return 0;
}