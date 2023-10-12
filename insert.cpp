#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    int i, j;
    i = j = 0;
    for (i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    int temp1 = 0;
    int temp2 = 0;
    for (i = 0; i < n; i++)
    for (j = 0; j < i; j++)
    if (a[i] < a[j])
    {
        temp1 = a[i];
        for (temp2 = i; temp2 > j; temp2--)
        a[temp2] = a[temp2 - 1];
        a[j] = temp1;
        break;
     }
     for(i = 0; i < n; i++)
     cout << a[i] << " ";
     return 0;
}