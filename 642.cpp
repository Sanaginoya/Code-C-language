#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double price1, price2;
    int amount1, amount2;
    cin >> price1 >> price2 >> amount1 >> amount2;
    double sum1 = 0, sum2 = 0;
    if (amount1 + amount2 == 2)
    sum1 = round((amount1 * price1 + amount2 * price2) * 0.9);  
    else if (amount1 + amount2 == 3 || amount1 + amount2 == 4)
    sum1 = round((amount1 * price1 + amount2 * price2) * 0.8);
    else if ((amount1 + amount2) >= 5)
    sum1 = round((amount1 * price1 + amount2 * price2) * 0.7);
    else if ((amount1 + amount2) < 2)
    sum1 = round(amount1 * price1 + amount2 * price2);
    sum2 = amount1 * price1 + amount2 * price2;
    sum2 = sum2 - (int)(sum2 / 500) * 100;
    if (sum1 <= sum2)
    cout << 1 << " " << fixed << setprecision(1) << sum1;
    else
    cout << 2 << " " << fixed << setprecision(1) << sum2;
    return 0;
}