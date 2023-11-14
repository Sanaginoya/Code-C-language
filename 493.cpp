#include <iostream>
#include <cmath>
using namespace std;
int judge1 (int a)
{
    int i1 = 0;
    for (i1 = 2; i1 <= sqrt(double(a)); i1++)
    {
        if (a % i1 == 0)
        return 0;
    }
    return 1;
}
int judge2 (int b)
{
    int a[6];
    int i2;
    for (i2 = 0; ; i2++)
    {
        if (b / 10 != 0)
        {
            a[i2] = b % 10;
            b = b /10;
        }
        else
        {
            a[i2] = b % 10;
            break;
        }
    }
    int left = 0;
    int right = i2 ;
    while (left <= right)
    {
        if (a[left] == a[right])
        {
            left = left + 1;
            right = right - 1;
        }
        else
        {
            return 0;
        }
        
    }
    return 1;
}
int summ (int c)
{
    int a[6];
    int i2;
    int sum2 = 0;
    for (i2 = 0; ; i2++)
    {
        if (c / 10 != 0)
        {
            a[i2] = c % 10;
            c = c / 10;
        }
        else
        {
            a[i2] = c % 10;
            break;
        }
    }
    for (int i3 = 0; i3 <= i2; i3++)
    sum2 += a[i3];
    return sum2;
}
int main()
{
    int m, n;
    cin >> m >> n;
    int i, p = 0;
    int j, k;
    int an[10000][2] = {0};
    for (i = 0; i < 10000; i++)
    {
        an[i][0] = 0;
        an[i][1] = 0;
    }
    for (i = m; i < n + 1; i++)
    {
        if (judge1(i) == 1 && judge2(i) ==1)
        {
            an[p][0] = i;
            p++;
        }
    }
    if (an[0][0] == 0)
    {
        cout << "0 0";
    goto exit;
    }
    for (i = 0; i < p; i++)
    {
        an[i][1] = summ(an[i][0]);
    }
    int temp1, temp2;
    for (i = 0; i < p - 1; i++)
    {
        for (j = 0; j < p - 1 - i; j++)
        {
            if (an[j][1] < an[j + 1][1])
            {
                temp1 = an[j][1];
                an[j][1] = an[j + 1][1];
                an[j + 1][1] = temp1;
                temp2 = an[j][0];
                an[j][0] = an[j + 1][0];
                an[j + 1][0] = temp2;
            }
        }
    }
    cout << an[0][0] << " " <<an[0][1];
exit : return 0;
}