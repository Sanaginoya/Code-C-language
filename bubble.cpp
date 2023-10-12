#include <iostream>
using namespace std;
void bubble (int a[], int sz)
{
    int sign = 0;
    int p = 0, q = 1;
    int m = 1;
    for (m = 1; m <= (sz - 1); m++)
    {
        for (p = 0, q = 1; q <= (sz - m); p++, q++)
    {
        if (a[p] > a[q])
        {
             int temp = 0;
             temp = a[q];
             a[q] = a[p];
             a[p] = temp;
             sign++;
        }
    }
    if (sign == 0)
    {
        break;
    }
    sign = 0;
}
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    cin >> a[i];
    int sz = sizeof (a) / sizeof (a[0]);
    bubble (a, sz);
    for(int j = 0; j < n; j++)
    cout << a[j] << " ";
    return 0;
}