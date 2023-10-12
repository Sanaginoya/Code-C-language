#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n+2][n+2];
    int i;
    int j1 = 0;
    int j2 = 0;
    int sum = 1;
    for (i = 1; i <= n; i++)
    {
        if(i % 2 != 0)
        {
            for (j1 = 1; j1 <= i; j1++)
            {
                a[i][j1] = sum;
                sum ++;
            }
            for (j1 = i - 1; j1 >= 1; j1--)
            {
                a[j1][i] = sum;
                sum ++;
            }
        }
        else if(i % 2 == 0)
            {
                for (j1 = 1; j1 <= i; j1++)
            {
                a[j1][i] = sum;
                sum ++;
            }
                for (j1 = i - 1; j1 >= 1; j1--)
            {
                a[i][j1] = sum;
                sum ++;
            }
            }
        }
        for(j1 = 1; j1 <= n; j1++)
        for(j2 = 1; j2 <= n; j2++)
        {
            cout << a[j1][j2] << " ";
            if (j2 == n)
            cout <<endl;
        }
        return 0;
    }
