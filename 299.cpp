#include <iostream>
#include <cmath>
using namespace std;
int judge (int a)
{
    int i1 = 2;
    for (i1 = 2; i1 <= sqrt(a); i1++)
    {
        if (a % i1 == 0)
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    int i = 2;
    int sum = 0;
    for (i = 2; i <= n; i++)
    {
        if (judge(i) == 0)
        {
            while(1)
            {
                if (n % i == 0)
            {
                n = n / i;
                sum++;
            }
                else
                {
                    if (sum != 0)
                    cout << i << ":" << sum <<endl;
                    break;
                }
            }
        }
        sum = 0;
        if (n == 1)
        break;
    }
    return 0;
}