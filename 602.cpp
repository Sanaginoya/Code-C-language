#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int judge (int a)
{
    if (a == 1)
    return 0;
    else
    {
        for (int i = 1; i <= sqrt(a); i++)
        if (i == 1)
        continue;
        else if (i > 1)
        {
            if (a % i == 0)
            return 0;
        }
        return 1;
    }
}
int mid_search (int ori[], int a, int left, int right)
{
    if (left > right)
    return -1;
    int mid = (left + right) / 2;
    if (ori[mid] == a)
    return mid;
    else if (ori[mid] > a)
    return mid_search(ori, a, left, mid - 1);
    else if (ori[mid] < a)
    return mid_search(ori, a, mid + 1, right);
}
int main()
{
    int n;
    cin >> n;
    int number[n];
    int ori[1000] = {0};
    int i, j, k;
    for (i = 0; i < n; i++)
    scanf("%d", &number[i]);
    int kinds[n] = {0};
    int maxn = 0;
    for (i = 0; i < n; i++)
    maxn = (maxn > number[i]) ? maxn : number[i];
    int flag = 0;
    for (i = 1; i < maxn; i++)
    {
        if ((judge(i) == 1) && (i < 1000))
        {
            ori[flag] = i;
            flag++;
        }
        else if (i >= 1000)
        break;
    }
    for (i = 0; i < n; i++)
    {
        if (ori[flag - 1] + ori[flag - 2] + ori[flag - 3] >= number[i]){
        for (j = 0; j < flag - 2; j++)
        {
            if (ori[j] < number[i])
            for (k = j + 1; j < flag - 1; k++)
            {
                if (ori[j] + ori[k] < number[i])
                {
                    int mid = mid_search(ori, number[i] - ori[j] - ori[k], k + 1, flag - 1);
                    if (mid != -1)
                    kinds[i]++;
                    else
                    continue;
                }
                else
                break;
            }
            else
            break;
        }
        }
        else
        continue;
    }
    for (i = 0; i < n; i++)
    printf("%d ", kinds[i]);
    return 0;
}