#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
using namespace std;
long long judge (long long a)
{
    char a1[30];
    sprintf(a1, "%lld", a);                 //long long是lld
    int length = strlen(a1);
    int i, j;
    i = 0;
    j = length - 1;
    while(i < j)
    {
        if (a1[i] == a1[j])
        {
            i++;
            j--;
        }
        else
        return 0;
    }
    return 1;
}
long long turn (long long a)
{
    char a1[30];
    sprintf(a1, "%lld", a);
    int length = strlen(a1);
    int i, j;
    long long result = 0;
    for (i = 0; i < length; i++)
    {
        j = a % 10;
        a = a / 10;
        result = result + pow(10, length - i - 1) * j;
    }
    return result;
}
int main()
{
    long long a[10];
    int i;
    for (i = 0; i < 10; i++)
    cin >> a[i];
    long long times[10] = {0};
    long long result[10];
    for (i = 0; i < 10; i++)
    result[i] = a[i];
    for (i = 0; i < 10; i++)
    {
        while (1){
        if (judge(result[i]) != 1)
        {
            result[i] = result[i] + turn(result[i]);
            times[i]++;
        }
        else
        break;
        }
    }
    long long j, k, temp1, temp2, temp3;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (times[j] < times[j + 1])
            {
                temp1 = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp1;
                temp2 = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp2;
                temp3 = times[j];
                times[j] = times[j + 1];
                times[j + 1] = temp3;
            }
            if (times[j] == times[j + 1])
            {
                if (result[j] > result[j + 1])
                {
                    temp1 = result[j];
                    result[j] = result[j + 1];
                    result[j + 1] = temp1;
                    temp2 = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp2;
                }
                if (result[j] == result[j + 1])
                {
                    if (a[j] > a[j + 1])
                    {
                        temp2 = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp2;
                    }
                }
            }
        }
    }
    for (i = 0; i < 10; i++)
    cout << a[i] << " " << times[i] << " " << result[i] <<endl;
    return 0;
}