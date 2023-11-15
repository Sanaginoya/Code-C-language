#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double a;
    cin >> a;
    if (a < 0)
    cout << fixed << setprecision(2) << -a;
    else if (a >= 0 && a <= 1)
    cout << fixed << setprecision(2) << sqrt(a);
    else
    cout << fixed <<setprecision(2) << pow (a, 2);
    return 0;
}