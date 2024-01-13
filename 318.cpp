#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char picture[n][n];
    char pic1[n][n];
    char pic2[n][n];
    char pic3[n][n];
    char pic4[n][n];
    int m, i, j, flag = 0;
    cin >> m;
    int a[4] = {1, 0, 0, 0};
    for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    cin >> picture[i][j];
    for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    {
        pic1[i][j] = picture[i][n - 1 - j];
    }
    for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    {
        pic2[i][j] = picture[n - 1 - i][j];
    }
    for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    {
        pic3[i][j] = picture[n - 1 - j][n - 1 - i];
    }
    for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    {
        pic4[i][j] = picture[j][i];
    }
    for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    {
        if (pic1[i][j] != pic2[i][j])
        flag++;
        if (i == n - 1 && j == n - 1)
        {
            if (flag != 0)
            {
                a[1] = 1;
            }
        }
    }
    flag = 0;
    for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    {
        if (pic1[i][j] != pic3[i][j])
        flag++;
        if (i == n - 1 && j == n - 1 && flag != 0)
        {
            if (a[1] != 0)
            {
                flag = 0;
                for (int p = 0; p < n; p++)
                for (int q = 0; q < n; q++){
                if (pic2[p][q] != pic3[p][q])
                flag++;
                if (p == n - 1 && q == n - 1)
                {
                    if (flag != 0)
                    {
                        a[2] = 1;
                    }
                }
                }
            }
            else
            {
                a[2] = 1;
            }
        }
    }
    flag = 0;
    for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    {
        if (pic1[i][j] != pic4[i][j])
        flag++;
        if (i == n - 1 && j == n - 1 && flag != 0)
        {
            flag = 0;
            for (int p = 0; p < n; p++)
            for (int q = 0; q < n; q++)
            {
                if (pic2[p][q] != pic4[p][q])
                flag++;
                if (p == n - 1 && q == n - 1 && flag != 0)
                {
                    flag = 0;
                    for(int c = 0; c < n; c++)
                    for(int b = 0; b < n; b++){
                    if (pic3[c][b] != pic4[c][b])
                    flag++;
                    if (c == n - 1 && b == n - 1 && flag != 0)
                    {
                        a[3] = 1;
                    }
                    }
                }
            }       
        }
    }
    if (m == 0)
    {
        cout << a[1] + a[0] << endl;
        for (i = 0; i < n; i++)
        for (j = 0; j < n; j++){
        cout << pic1[i][j];
        if (j == n - 1)
        cout << endl;
        if (i == n - 1 && j == n - 1)
        cout << endl;
        }
        if (a[1] == 1)
        for (i = 0; i < n; i++)
        for (j = 0; j < n; j++){
        cout << pic2[i][j];
        if (j == n - 1)
        cout << endl;
        }
    }
    else if(m == 1)
    {
        cout << a[1] + a[2] + a[3] + a[0] << endl;
        for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
        cout << pic1[i][j];
        if (j == n - 1)
        cout << endl;
        if (i == n - 1 && j == n - 1)
        cout << endl;
        }
        if (a[1] == 1){
        for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
        cout << pic2[i][j];
        if (j == n - 1)
        cout << endl;
        if (i == n - 1 && j == n - 1)
        cout << endl;
        }
        }
        if (a[2] == 1)
        {
            for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
        cout << pic3[i][j];
        if (j == n - 1)
        cout << endl;
        if (i == n - 1 && j == n - 1)
        cout << endl;
        }
        }
        if (a[3] == 1)
        {
        for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
        cout << pic4[i][j];
        if (j == n - 1)
        cout << endl;
        }
        }
    }
    return 0;
}