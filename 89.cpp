#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cin >> n;
    struct bon
    {
        int number;
        double percent;
    } bonus[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        cin >> bonus[i].number >> bonus[i].percent;
    }
    int profit;
    cin >> profit;
    double sum = 0;
    if (profit < 0)
    {
        cout << "NO";
        goto exit;
    }
    if (profit == 0)
    {
        cout << "0.00";
        goto exit;
    }
    for (i = 0; i < n; i++)                                // You need to pay attention to all situations , to avoid leaving some special examples.
    {
        if (i == 0 && profit <= bonus[i].number && i != n - 1)
        {
            sum += profit * bonus[i].percent;
            break;
        }
        else if (i == 0 && profit > bonus[i].number && i != n - 1)
        sum += bonus[i].number * bonus[i].percent;
        if (i != 0 && profit > bonus[i - 1].number && profit <= bonus[i].number && i != n - 1)
        {
            sum += (profit - bonus[i - 1].number) * bonus[i].percent;
            break;
        }
        else if (i != 0 && profit > bonus[i].number && i != n - 1)
        {
            sum += (bonus[i].number - bonus[i - 1].number) * bonus[i].percent;
        }
        if (i == n - 1 && i != 0)
        sum += (profit - bonus[i - 1].number) * bonus[i].percent;
        if (i == n - 1 && i == 0)
        sum += profit * bonus[i].percent;
    }
    cout << fixed << setprecision(2) << sum;
exit:  return 0;
}