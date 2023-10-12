#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    int i = 0, j = 0;
    for(i = 0; i < n; i++)
    cin >> a[i];
    int temp;
    for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n; j++)
    {
        if (a[i] > a[j])
        {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    for (i = 0; i < n; i++)
    cout << a[i] << " ";
    return 0;
}