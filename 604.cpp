#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    int a[N];
    memset (a, 0, 4 * N);
    int i = 0;
    int j = 0;
    int k = 0;
    int temp = 0;
    for (i = 0; i < N - 1; i++)
    {
        for (j = temp;; j++)
        {
            if (a[j % N] == 0)               //通过取模来形成环状结构
            {
                k++;
                if (k == M)
                {
                    a[j % N] = 1;
                    k = 0;
                    temp = j % N;
                    break;
                }
            }         
        }
    }
    for (i = 0; i < N; i++)
    if (a[i] == 0)
    {
        cout << i + 1;
        break;
    }
    return 0;
}