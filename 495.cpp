#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double n, a, b, c;
    cin >> n >> a >> b >> c;
    double result;
    if (n >= 300)
    result = n - floor(n / 300) * 40;
    else
    result = n;
    if (result >= a)
    result -= b;
    result -= c;
    if (result <= 0.00)
    cout << "0.00";
    else
    cout << fixed << setprecision(2) << result;
    return 0;
}