#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int matrix[m + 2][n + 2];                          //是变量的话二维数组不能直接写={0}初始化，必须使用memset
    memset(matrix, 0, 4 * (m + 2) * (n + 2));
    int i, j;
    int row[10000], col[10000];
    for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++)
    cin >> matrix[i][j];
    long long min = 10000000000, temp = 0, times = 0;
    for (i = m; i >= 1; i--)
    {
        for (j = n; j >= 1; j--)
        {
            temp = matrix[i][j] + matrix[i - 1][j - 1] + matrix[i - 1][j + 1] + matrix[i + 1][j - 1] + matrix[i + 1][j + 1];
            if (temp < min)
            {
                times = 0;
                min = temp;
                row[times] = i;
                col[times] = j;
            }
            else if (temp == min)
            {
                times++;
                row[times] = i;
                col[times] = j;
            }
        }
    }
    cout << min << " " << times + 1 << endl;
    for (i = 0; i <= times; i++)
    cout << row[i] - 1 << " " << col[i] - 1 <<endl;
    return 0;
}