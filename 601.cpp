#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int seat[n][m];
    int i, j;
    int sit1 = 0, sit2 = 0;
    for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
    scanf("%d", &seat[i][j]);
    for (i = 0; i < n; i++){
    for (j = 0; j < m; j++)
    {
        if (j == 0 && ((seat[i - 1][j] == 0 && i > 0) || ((i == 0) && (seat[i][j] == 0))))
        seat[i][j] = 2;
        else if (seat[i][j] == 1)
        continue;
        else if ((j != 0) && (seat[i][j] == 0))
        {
            if (i == 0)
            {
                if (seat[i][j - 1] != 2)
                seat[i][j] = 2;
                else
                continue;
            }
            else if (i != 0)
            {
                if (seat[i][j - 1] != 2 && seat[i - 1][j] != 2)
                seat[i][j] = 2;
            }
        }
    }
    if (i == 0)
    {
        for (int k = 0; k < m; k++)
        if (seat[0][k] == 2)
        sit1++;
    }
    if (i == 1)
    {
        for (int k = 0; k < m; k++)
        if (seat[1][k] == 2)
        sit2++;
        break;
    }
    }
    int sum1 = 0, sum2 = 0;
    for (i = 0; i < n; i++)
    if ((i + 1) % 2 != 0)
    sum1 += sit1;
    else
    sum1 += sit2;
    for (i = 0; i < n; i++)
    if ((i + 1) % 2 != 0)
    sum2 += sit2;
    else
    sum2 += sit1;
    cout << ((sum1 > sum2) ? sum1 : sum2);
    return 0;
}