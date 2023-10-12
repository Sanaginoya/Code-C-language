#include <iostream>
using namespace std;
int main()
{
    double sum, k, i;
    sum = 0.0;
    i = 1.0;
    cin >> k;
    while (sum <= k)
    {
        sum = sum + 1.0/i;
        i = i + 1.0;
    }
    cout << (int)(i - 1) <<endl;
    return 0;
}