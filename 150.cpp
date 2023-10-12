#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int score[n + 1][2];
    int i, j, k;
    for (i = 0; i < n; i++)
    cin >> score[i][0] >> score[i][1];
    score[n][1] = score[n][0] = 10000;
    int rank[n] = {0};
    int flag = 0;
    int temp1 = 0, temp2 = 0;
    for (i = 0; i < n - 1; i++)                     //先排成绩，并交换学号
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (score[j][1] < score[j + 1][1])
            {
                temp1 = score[j + 1][1];
                score[j + 1][1] = score[j][1];
                score[j][1] = temp1;
                temp2 = score[j + 1][0];
                score[j + 1][0] = score[j][0];
                score[j][0] = temp2;
                flag++;
            }
        }
         if (flag == 0)
            break;
            flag = 0;
    }
    flag = 0;
    for (i = 0; i < n; i++)                  //再对成绩相同的排序学号
    {
        if(score[i][1] == score[i + 1][1])   //易错 ；如果最后几个数都相同，会缺少一次排序    改进：只要把数组再扩展一位即可。
        {
            flag ++;
            continue;
        }
        if (flag != 0)
        {
           for (j = i - flag; j < i; j++)
           {
            temp1 = score[j][0];
            for(k = j + 1; k <= i; k++)
            {
                if(score[k][0] < temp1)
                {
                    score[j][0] = score[k][0];
                    score[k][0] = temp1;
                    temp1 = score[j][0];
                }
            }
           }
           flag = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        rank[i] = i + 1;
    }
    for (j = 0; j < n - 1; j++)                  //最后写上对应名次
    {
        if (score[j][1] == score[j + 1][1])
        {
            rank[j + 1] = rank[j];
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << rank[i] << " " << score[i][0] << " " << score[i][1] <<endl;
    }
    return 0;
}