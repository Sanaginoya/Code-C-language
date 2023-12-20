#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int unity[10][100];
int sum[10] = {0};
int sign[101] = {0};
int sumsign[10] = {0};
int number = 0;
int row = 0;
void my_row (int flag, int sign, int answer[], int n)
{
    int i, j;
    if (sign == flag)
    {
        row++;
        printf("%d. ", row);
        for (i = 0; i < n; i++)
        printf("%d ", answer[i]);
        cout <<endl;
        return;
    }
    for (i = 0; i < flag; i++)
    {
        if (sumsign[i] == 0)
        {
            for (j = 0; j < sum[i]; j++)
            {
                answer[number] = unity[i][j];
                number++;
            }
            sumsign[i] = 1;
            my_row(flag, sign + 1, answer, n);
            for (j = 0; j < sum[i]; j++)
            {
                number--;
                answer[number] = 0;
            }
            sumsign[i] = 0;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int i, j, k;
    for (i = 0; i < m; i++)
    {
        cin >> sum[i];
        for (j = 0; j < sum[i]; j++)
        {
            cin >> unity[i][j];
            sign[unity[i][j]] = 1;
        }
    }
    int answer[n] = {0};
    int flag = 0;
    for (i = m; ; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (sign[j] == 0)
            {
                sum[i] = 1;
                unity[i][0] = j;
                sign[j] = 1;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        break;
        else
        flag = 0;
    }
    int temp1, temp2[100];
    for (j = 0; j < i - 1; j++)
    {
        for (k = 0; k < i - 1 - j; k++)
        {
            if (unity[k][0] > unity[k + 1][0])
            {
                memcpy(temp2, &unity[k][0], 4 * sum[k]);
                memcpy(&unity[k][0], &unity[k + 1][0], 4 * sum[k + 1]);
                memcpy(&unity[k + 1][0], temp2, 4 * sum[k]);
                temp1 = sum[k];
                sum[k] = sum[k + 1];
                sum[k + 1] = temp1;
            }
        }
    }
exit:   my_row(i, 0, answer, n);
    return 0;
}