#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    long long a[n];
    long long b[n];
    long long c[n];
    long long d[n];
    long long e[n];
    long long x[n];
    long long ans1[n];
    long long ans2[n];
    int i, j;
    for (i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i] >> x[i] >> ans1[i] >> ans2[i];
    }
    int flag1 = 0, flag2 = 0;
    int result1 = 0, result2 = 0;
    for (i = 0; i < n; i++)
    {
        int right = a[i] * pow(x[i], 4) + b[i] * pow(x[i], 3) + c[i] * pow(x[i], 2) + d[i] * pow(x[i], 1) + e[i];
        if (ans1[i] == right)
        {
            flag1++;
            result1++;
            if (flag1 > k)
            result1 += (flag1 - k);
        }
        else
        flag1 = 0;
        if (ans2[i] == right)
        {
            flag2++;
            result2++;
            if (flag2 > k)
            result2 += (flag2 - k);
        }
        else
        flag2 = 0;
    }
    cout << result1 << " " << result2;
    return 0;
}