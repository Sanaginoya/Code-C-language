#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    int i, j, k, p;
    for (i = 0; i < n; i++)
    cin >> a[i];
    int flag = 0;
    for (i = 0; i < n - 3; i++)
    {
        if (a[i] < m){
        for (j = i + 1; j < n - 2; j++)
        {
            if ((a[j] <= m) || (a[i] + a[j] < m)){
            for (k = j + 1; k < n - 1; k++)
            {
                if ((a[k] <= m)|| (a[i] + a[j] + a[k] <= m)){
                for (p = k + 1; p < n; p++)
                {
                    if (a[p] <= m)
                    if (a[i] + a[j] + a[p] + a[k] == m)
                    flag++;
                }
                }
            }
        }
        }
        }
    }
    cout << flag;
    return 0;
}