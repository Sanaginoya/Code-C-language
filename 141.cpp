#include <iostream>
using namespace std;
int main ()
{
    int i, j;
    cin >> i >> j;
    int a[i + 2][j + 2];
    int i1, j1;
    for (i1 = 0; i1 < i + 2; i1++)
    for (j1 = 0; j1 < j + 2; j1++)
    a[i1][j1] = 0;
    for (i1 = 1; i1 < i + 1; i1++)
    for (j1 = 1; j1 < j + 1; j1++)
    cin >> a[i1][j1];
    int b[i][j];
    for (i1 = 0; i1 < i; i1++)
    for (j1 = 0; j1 < j; j1++)
    b[i1][j1] = 0;
    for (i1 = 0; i1 < i; i1++)
    for (j1 = 0; j1 < j; j1++)
    {
        b[i1][j1] = a[i1 + 1][j1 + 1] + a[i1 + 1][j1] + a[i1 + 1][j1 + 2] + a[i1 + 2][j1 + 1] + a[i1][j1 + 1];
    }
    int r[200] = {0}, c[200] = {0};
    int temp, sum = 0;
    temp = b[0][0];
    for (i1 = 0; i1 < i; i1++)
    for (j1 = 0; j1 < j; j1++)
    {
         if(b[i1][j1] > temp)
         temp = b[i1][j1];
    }
    int i2 = 0, j2 = 0;
    for (i1 = 0; i1 < i; i1++)
    for (j1 = 0; j1 < j; j1++)
    {
        if(temp == b[i1][j1])
        {
            sum++;
            r[i2] = i1;
            c[j2] = j1;
            i2++;
            j2++;
        }
    }
    cout << temp <<" " << sum << endl;
    for (i1 = 0, j1 = 0; i1 < i2; i1++,j1++)
    cout << r[i1] << " " << c[j1] <<endl;
    return 0;

}