#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, b, n, k, m;
    cin >> a >> b >> n >> k >> m;
    int i = 0;
    int sum = 0;
    for (i = a; i <= b; i++)
    {
        if((i - n) % 10 == 0 && i % k == 0 && i < pow(10,m) && i >= pow(10,(m-1)))
        sum += 1;
    }
    cout << sum;
    return 0;
}