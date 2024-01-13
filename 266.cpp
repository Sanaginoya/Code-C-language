#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int matrix[n][m];
    int i, j;
    for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
    {
        cin >> matrix[i][j];
    }
    int rotate;
    cin >> rotate;
    if (rotate == 0)
    for(i = 0; i < n; i++)
    {
    for(j = 0; j < m; j++)
    cout << matrix[i][j] << " ";
    cout <<endl;
    }
    else if (rotate > 0)
    {
        int number = (rotate / 90) % 4;
        if (number == 1)
        for(i = 0; i < m; i++)
        {
        for(j = n - 1; j >= 0; j--)
        cout <<matrix[j][i] << " ";
        cout << endl;
        }
        else if (number == 2)
        for (i = n - 1; i >= 0; i--)
        {
            for (j = m - 1; j >= 0; j--)
            cout << matrix[i][j] << " ";
            cout << endl;
        }
        else if (number == 3)
        for (i = m - 1; i >= 0; i--)
        {
            for (j = 0; j < n; j++)
            cout << matrix[j][i] << " ";
            cout << endl;
        }
        else if(number == 0)
        for(i = 0; i < n; i++)
        {
        for(j = 0; j < m; j++)
        cout << matrix[i][j] << " ";
        cout <<endl;
        }
    }
    else if (rotate < 0)
    {
        int number = ((- rotate) / 90) % 4;
        if (number == 3)
        for(i = 0; i < m; i++)
        {
        for(j = n - 1; j >= 0; j--)
        cout <<matrix[j][i] << " ";
        cout << endl;
        }
        else if (number == 2)
        for (i = n - 1; i >= 0; i--)
        {
            for (j = m - 1; j >= 0; j--)
            cout << matrix[i][j] << " ";
            cout << endl;
        }
        else if (number == 1)
        for (i = m - 1; i >= 0; i--)
        {
            for (j = 0; j < n; j++)
            cout << matrix[j][i] << " ";
            cout << endl;
        }
        else if(number == 0)
        for(i = 0; i < n; i++)
        {
        for(j = 0; j < m; j++)
        cout << matrix[i][j] << " ";
        cout <<endl;
        }
    }
    return 0;
}
