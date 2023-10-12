#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int sta[m + 1];
    sta[0] = 0;
    int i, j;
    int score[n + 1][2];
    for (i = 1; i < m + 1; i++)
    {
        cin >> sta[i];
    }
    int student[n][m + 1];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m + 1; j++)
        cin >> student[i][j];
    }
    for (i = 0; i < n; i++)
    {            
        score[i][1] = 0;
        for (j = 1; j < m + 1; j++)
        {

            if (student[i][j] < 60)
            {
                continue;
            }
            else
            {
                score[i][1] += sta[j];
            }
        }
        score[i][0] = student[i][0];
    }
    score[n][0] = score[n][1] = 10000;
    int temp1 = 0, temp2 = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (score[j][1] < score[j + 1][1])
            {
                temp1 = score[j][1];
                score[j][1] = score[j + 1][1];
                score[j + 1][1] = temp1;
                temp2 = score[j][0];
                score[j][0] = score[j + 1][0];
                score[j + 1][0] = temp2; 
            }
        }
    }
    int flag = 0, k;
    int i1 = 0;
    temp1 = 0;
    for (k = 0; k < n; k++)
    {
        if (score[k][1] == score[k + 1][1])
        {
            flag++;
            continue;
        }
        if (flag != 0)
        {
            for (i = k - flag; i < k; i++)
            {
                for (j = k - flag; j < k - i1; j++)
                {
                    if (score[j][0] > score[j + 1][0])
                    {
                        temp1 = score[j][0];
                        score[j][0] = score[j + 1][0];
                        score[j + 1][0] = temp1;
                    }
                }
                i1++;
            }
            flag = 0;
            i1 = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << score[i][0] << " " << score[i][1] <<endl;
    }
    return 0;
}