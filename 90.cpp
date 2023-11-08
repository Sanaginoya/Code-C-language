#include <iostream>
using namespace std;
int find(int a1[], int n1, int n2)   //二分查找使用条件： 有序数组
{
    int left = 0;
    int right = n2 - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a1[mid] < n1)
        left = mid + 1;
        else if (a1[mid] > n1)
        right = mid - 1;
        else if (a1[mid] == n1)
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    int temp1, temp2;
    cin >> n;
    int a[n];
    int i, j, p;
    for (i = 0; i < n; i++)
    cin >> a[i];
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp1 = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp1;
            }
        }
    }
    int m, k;
    cin >> m >> k;
    struct student
    {
        int sym;
        int tot;
        int pro[200];
    } stu[m];
    int flag = 0;
    for (j = 0; j < m; j++)
    {
        cin >> stu[j].sym >> stu[j].tot;
        for (i = 0; i < stu[j].tot; i++)
        cin >> stu[j].pro[i];
    }
    int sum = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < stu[i].tot; j++)
        {
            if (find(a, stu[i].pro[j], n) == 1)
            sum += 1;
            else
            continue;
        }
        stu[i].tot = sum;
        sum = 0;
    }
    for (i = 0; i < m - 1; i++)
    {
        flag = 0;
        for (j = 0; j < m - 1 - i; j++)
        {
            if (stu[j].tot < stu[j + 1].tot)
            {
                temp1 = stu[j].tot;
                stu[j].tot = stu[j + 1].tot;
                stu[j + 1].tot = temp1;
                temp2 = stu[j].sym;
                stu[j].sym = stu[j + 1].sym;
                stu[j + 1].sym = temp2;
                flag = 1;
            }
        }
        if (flag == 0)
        break;
    }
    flag = 0;
    int i1 = 0;
    for (i = 0; i < m - 1; i++)
    {
        if(stu[i].tot == stu[i + 1].tot)
        {
            flag++;
            if (i != m - 2)
            continue;
            else
            {
                i++;
                goto change;
            }
        }
change:     if (flag != 0)
        {
            for (j = i - flag; j < i; j++)
            {
                for (p = i - flag; p < i - i1; p++)
                {
                    if (stu[p].sym > stu[p + 1].sym)
                    {
                        temp1 = stu[p].sym;
                        stu[p].sym = stu[p + 1].sym;
                        stu[p + 1].sym = temp1;
                    }
                }
                i1++;
            }
            flag = 0;
            i1 = 0;
        }
    }
    sum = 0;
    j = 0;
    for (i = 0; i < k; i++)
    {
        cout << stu[j].sym << " ";
        while(1)
        {
            if (j == m - 1)
            {
                goto exit;
            }
            if (stu[j].tot == stu[j + 1].tot)
            {
                cout << stu[j + 1].sym << " ";
                j++;
            }
            else
            {
                j++;
                break;
            }
        }
    }
exit:    return 0;
} 