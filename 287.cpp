#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, i, m, sum, a, b;
    a = 0;
    sum = 0;
    cin >> n;
    for (i = 1;; i++)
    {
        m = pow(10,i);
        if (n % m == n)
        {
            sum++;
            cout << (n - a)/ pow(10,(i - 1)) <<",";
            break;
        }
        else
        {
            sum++;
            b = a;
            a = n % m;
            cout << (a - b)/ pow(10,(i - 1)) <<",";
        }
    }
    cout << sum;
    return 0;
}