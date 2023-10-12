#include <iostream>
using namespace std;
int judge (int a, int b, int c, int d)
{
    int x[4], y[4];
    x[0] = (a % 10);
    x[1] = ((a / 10) % 10);
    x[2] = ((a / 100) % 10);
    x[3] = (a / 1000);
    y[0] = (b % 10);
    y[1] = ((b / 10) % 10);
    y[2] = ((b / 100) % 10);
    y[3] = (b / 1000);
    int a_2, a_3;
    a_2 = a_3 = 0;
    int p, q;
    p = q = 0;
    for (p = 0; p <= 3; p++)
    {
        for (q = 0; q <= 3; q++)
        if (x[p] == y[q])
        {
            a_2++;
            y[q] = -1;
            break;
        }
    }
    y[0] = (b % 10);
    y[1] = ((b / 10) % 10);
    y[2] = ((b / 100) % 10);
    y[3] = (b / 1000);
    for (p = q = 0; p <= 3; p++, q++)
    {
        if(x[p] == y[q])
        {
            a_3++;
        }
    }
    if (a_2 == c && a_3 == d)
    return 1;
    else
    return 0;
}



int main ()
{
    int n, i;
    int a1[11], a2[11], a3[11];
    int answer = 0;
    int sum1, sum2;
    sum1 = sum2 = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    cin >> a1[i] >> a2[i] >> a3[i];
    for (int j = 1000; j <= 9999; j++)
    {
        for(int m = 0; m < n; m++)
        {
            if (judge (j, a1[m], a2[m], a3[m]) == 1)
            {
                sum1 ++;
            }
        }
        if (sum1 == n)
        {
           answer = j;
           sum2++;
        }
        sum1 = 0;
    }
    if (sum2 == 1)
    cout << answer <<endl;
    else
    {
        cout << "Not sure" <<endl;
    }
    return 0;
}