#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
/* int ban[9000001] = {0};
int temp;
int main()
{
    int n;
    cin >> n;
    int jia[n];
    int i, j = 1, k;
    char s1[10];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &jia[i]);
    }
    for (i = 1; i <= 9000000; i++)
    {
        if (ban[i] == 0)
        {
        sprintf(s1, "%d", i);
        for (k = 0; k < strlen(s1); k++)
        {
            if (s1[k] == '9')
            {
               ban[i] = 1;
               break;
            }
        }
        }
        if (ban[i] == 1)
        {
            for (k = 1; k < 9000000 / i; k++)
            {
                ban[i * k] = 1;
            }
        }
    }
    int answer[n];
    for (i = 0; i < n; i++)
    {
        if (jia[i] < 9000001)
        {
        if (ban[jia[i]] == 1)
        answer[i] = -1;
        else
            {
                k = 1;
            while(ban[jia[i] + k] == 1)
            {
                k++;
            }
            answer[i] = jia[i] + k;
            }
            }
        else
        answer[i] = 10000000;
    }
    for (i = 0; i < n; i++)
    printf("%d\n", answer[i]);
    return 0;
} */
/* int number[10001000] = {0};
int nxt[10001000] = {0};
int judge (int n)
{
    char s[10];
    sprintf(s, "%d", n);
    int i = 0;
    while(s[i])
    {
        if(s[i] == '9')                 //需要注意数组名是指针常量因而不能加一， next是C语言关键词
        return 1;
        else
        i++;
    }
    return 0;
}
void init()
{
    int i, j, k = 1;
    for (i = 1; i <= 10001000; i++)
    {
        if (number[i])
        continue;
        if (judge(i))
        {
            number[i] = 0;
            j = i + i;
            while (j <= 10001000)
            {
                number[j] = 1;
                j += i;
            }
        }
        else
        {
            nxt[k] = i;
            k = i;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int jia[n];
    int i, j;
    FILE* fp = fopen("D:\\xunlei_download\\error.in", "r");
    FILE* fpout = fopen("D:\\xunlei_download\\error1.out", "w");
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &jia[i]);
    }
    init();
    for (i = 0; i < n; i++)
    {
        if (nxt[jia[i]] == 0)
        fprintf(fpout, "-1\n");
        else
        fprintf(fpout, "%d\n", nxt[jia[i]]);
    }
    fclose(fp);
    fclose(fpout);
    return 0;
} */
int number[10000010] = {0};
int nxt[10000010] = {0};
int judge (int n)
{
    char s[10];
    sprintf(s, "%d", n);
    int i = 0;
    while(s[i])
    {
        if(s[i] == '9')                 //需要注意数组名是指针常量因而不能加一， next是C语言关键词， 不要用strlen，strlen会遍历数组导致时间复杂度倍增。
        return 1;
        else
        i++;
    }
    return 0;
}
void init()
{
    int i, j, k = 1;
    for (i = 1; i <= 10000010; i++)      //如果设置成10000000的话，10000000会无法正确计算！
    {
        if (number[i])
        continue;
        if (judge(i))                   //节省判断时间
        {
            number[i] = 0;
            j = i + i;
            while (j <= 10000010)
            {
                number[j] = 1;          //素晴らしいコードですね， 在判断的同时计算出了next，并利用了正向筛法。
                j += i;
            }
        }
        else
        {
            nxt[k] = i;
            k = i;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int jia[n];
    int i, j;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &jia[i]);
    }
    init();
    for (i = 0; i < n; i++)
    {
        if (nxt[jia[i]] == 0)
        printf("-1\n");
        else
        printf("%d\n", nxt[jia[i]]);
    }
    return 0;
}