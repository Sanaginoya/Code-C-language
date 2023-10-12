#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x, a, s, c;
    int i, j, m;
    i = j = 1;
    m = 2;
    long double S;
    S = 1;
    cin >> x >> a;
    double si, co;
    si = co = 0.0;
    if (x < 0)
    {
        while(fabs(x) > 2 * M_PI)
        x = x + 2 * M_PI;
    }
    else
    {
        while(fabs(x) > 2 * M_PI)
        x = x - 2 * M_PI;
    }
    s = sin(x);
    c = cos(x);
    do
    {
        for(i = 1; i <= ((2 * j)-1); i++)
        S = S * i;
        si = si + pow(-1,m) * pow(x,((2 * j)-1)) / S;
        m++;
        j += 1;
        S = 1;
    } while (fabs(s - si) >= a);
    j = 0;
    m = 2;
    do
    {
        for(i = 1; i <= (2 * j); i++)
        S = S * i;
        co = co + pow(-1,m) * pow(x,(2 * j)) / S;
        m++;
        j += 1;
        S = 1;
    } while (fabs(c - co) >= a);
    cout << si <<endl;
    cout << co <<endl;
    return 0;
    
    
}
