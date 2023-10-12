#include <iostream>
#include <cmath>
using namespace std;
int judge (int j)
{
    if (j == 1)                              //素数判断需注意特殊情况1，幂计算需注意0
    {
        cout <<"NO ";
        return 0;
    }
    int i1 = 2;
    for (i1 = 2; i1 <= sqrt(j); i1++)
    {
        if (j % i1 == 0)
        {
            cout << "NO ";
            return 0;
        }
    }
    cout <<"YES ";
    return 1;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    judge(a[i]);
    return 0;
}