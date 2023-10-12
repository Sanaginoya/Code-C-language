#include <iostream>
using namespace std;
int main()
{
    int a[100];
    int i;
    for(i = 0; i < 100; i++)
    {
        a[i] = i + 1;
    }
    for(i = 2; i < 100; i += 4)
    {
        a[i] = -a[i];
    }
    for(i = 3; i < 100; i += 4)
    {
        a[i] = -a[i];
    }
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for(; n <= m; n++)
    {
        sum += a[n-1];
    }
    cout << sum;
    return 0;
}