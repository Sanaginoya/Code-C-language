#include <iostream>
using namespace std;
long long f (int i1)
{
    long long sum1 = 1;
    for (int j1 = 1; j1 < i1 + 1; j1++)
    sum1 *= j1;
    return sum1;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    int i, j = 0;
    long long sum = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n - 1; i++)
    {
        sum += (a[i] - 1) * f(n - 1 - i);
        for (j = i + 1; j < n; j++)
    {
        if (a[j] > a[i])
        a[j] = a[j] - 1;
    }
    }
    sum += a[n - 1];
    cout << sum;
    return 0;
}