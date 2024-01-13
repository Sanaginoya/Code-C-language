#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    float a;
    int b;
    cin >> a >> b;
    if (b == 1)
    cout << fixed << setprecision(2) << a;
    else if (b == 2)
    cout << fixed << setprecision(2) << 2 * a * 0.8;
    else if (b >= 3 && b <= 5)
    cout << fixed << setprecision(2) << a * b * 0.7;
    else if (b > 5)
    cout << fixed << setprecision(2) << (5 * a * 0.7 + a * (b - 5) * 1.1);
    return 0;
}