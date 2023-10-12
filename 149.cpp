#include <iostream>
using namespace std;
int main()
{
    int N, P, M;
    cin >> N >> P >> M;
    int a[N][P], b[P][M] , c[N][M];
    int i, j;
    for (i = 0; i < N; i++)
    for (j = 0; j < M; j++)
    c[i][j] = 0;
    for (i = 0; i < N; i++)
    for (j = 0; j < P; j++)
    cin >> a[i][j];
    for (i = 0; i < P; i++)
    for (j = 0; j < M; j++)
    cin >> b[i][j];
    for (i = 0; i < N; i++)
    for (j = 0; j < M; j++)
    {
        for(int i1 = 0, j1 = 0; i1 < P; i1++, j1++)
        {
            c[i][j] += a[i][i1] * b[j1][j];    
        }
    }
    for (i = 0; i < N; i++)
    for (j = 0; j < M; j++)
    {
        cout << c[i][j] <<" ";
        if (j == M - 1)
        cout <<endl;
    }
    return 0;
}