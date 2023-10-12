#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int sum = 0;
    int i;
    int a[6];
    int i1, i2, i3, i4, i5, i6;
    for (i = 0; i < n; i++)
    {
        for (int j1 = 0; j1 < 6; j1++)
        a[j1] = 0;
        i1 = i2 = i3 = i4 = i5 = i6 = 0;
        for (int j1 = 0; j1 < 6; j1++)
        cin >> a[j1];
        for (int j1 = 0; j1 < 6; j1++)
        {
            if (a[j1] == 1)
            i1 += 1;
            if (a[j1] == 2)
            i2 += 1;
            if (a[j1] == 3)
            i3 += 1;
            if (a[j1] == 4)
            i4 += 1;
            if (a[j1] == 5)
            i5 += 1;
            if (a[j1] == 6)
            i6 += 1;
        }
        if (i4 == 1 && (i2 != 1 || i3 != 1 || i4 != 1 || i5 != 1 || i6 != 1) && i2 != 5)
        {
            sum += 1;
        continue;
        }
        if (i4 == 2 && i2 != 4)
        {
            sum += 2;
        continue;
        }
        if (i2 == 4)
        {
            sum += 4;
        continue;
        }
        if (i4 == 3)
        {
            sum += 8;
        continue;
        }
        if (i4 == 4 && i1 != 2)
        {
            sum += 32;
        continue;
        }
        if (i1 == 1 && i2 == 1 && i3 == 1 && i4 == 1 && i5 == 1 && i6 == 1)
        {
            sum += 16;
            continue;
        }
        if (i2 == 5)
        {
            sum += 64;
            continue;
        }
        if (i2 == 6)
        {
            sum += 256;
            continue;
        }
        if (i4 == 5)
        {
            sum += 128;
            continue;
        }
        if (i4 == 6)
        {
            sum += 1024;
            continue;
        }
        if (i1 == 6)
        {
            sum += 512;
            continue;
        }
        if (i4 == 4 && i1 == 2)
        {
            sum += 2048;
            continue;
        }
        break;
    }
    printf("%x", sum);
    return 0;
}