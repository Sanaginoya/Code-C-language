#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[m];
    int i, j;
    for (i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    int max = 0, temp = m / 2;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        if (a[i] == a[j])
        max++;
        if (max > temp)
        {
            cout << a[i];
            goto exit;
        }
        max = 0;
    }
    cout << "-1";
exit:    return 0;
}