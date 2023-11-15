#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
long long mul10 (int a)
{
    int i = 0;
    long long sum = 1;
    for (i = 0; i < a; i++)
    {
        sum = sum * 10;
    }
    return sum;
}
long long mathify (char a1[])
{
    int len1 = strlen(a1);
    long long sum1 = 0;
    for (int i1 = 0; i1 < len1; i1++)
    {
        sum1 += ((int)a1[i1] - 48) * mul10(len1 - 1 - i1);
    }
    return sum1;
}
int cmp(const void* a1, const void* a2)                 //在这里需要注意返回值是int，无法返回long long类型的值，所以要展开三种情况
{
    if (-(*((long long*)a1) - *((long long*)a2)) == 0)
    return 0;
    else if (-(*((long long*)a1) - *((long long*)a2)) > 0)
    return 1;
    else if (-(*((long long*)a1) - *((long long*)a2)) < 0)
    return -1;
}
int main()
{
    char a[20];
    long long sum[1000] = {0};
    cin >> a;
    int pos = strlen(a) - 1;
    int i, j, k, p = 0;
    char temp1, temp2, temp3;
    char t1[15], t2[15], t3[15], t4[15];
    for (i = 1; i <= pos; i++)
    for (j = 1; j <= pos ;j++)
    for (k = 1; k <= pos; k++)
    {
        if (i != k && i != j && j != k && k > j && j > i)
        {
            temp1 = a[i];
            a[i] = '\0';
            strcpy(t1, a);
            a[i] = temp1;
            temp2 = a[j];
            a[j] = '\0';
            strcpy(t2, a + i);
            a[j] = temp2;
            temp3 = a[k];
            a[k] = '\0';
            strcpy(t3, a + j);
            a[k] = temp3;
            strcpy(t4, a + k);
            sum[p] = mathify(t1) + mathify(t2) + mathify(t3) + mathify(t4);
            p++;
        }
    }
    qsort(sum,1000,8,cmp);
    for (i = 0; i < 1000; i++)
    {
        if (sum[i] != 0)
        cout << sum[i] << " ";
        else
        {
            break;
        }
        
    }
    return 0;
}