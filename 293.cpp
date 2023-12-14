#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int i, j;
    for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
    cin >> a[i][j];
    int sum = 0;
    for (i = 0; i < m; i++){
    sum += a[0][i];
    a[0][i] = 0;
    }
    for (i = 0; i < m; i++){
    sum += a[n - 1][i];
    a[n - 1][i] = 0;
    }
    for (i = 0; i < n; i++){
    sum += a[i][0];
    a[i][0] = 0;
    }
    for (i = 0; i < n; i++){
    sum += a[i][m - 1];
    a[i][m - 1] = 0;
    }
    cout << sum;
    return 0;
}