#include <iostream>
using namespace std;
int main()
{
    int L, M;
    cin >> L >> M;
    int tree[L + 1] = {0};
    int a[M] = {0}, b[M] = {0};
    int i = 0;
    for(i = 0; i < M; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i1 = 0; i1 < M; i1++)
    {
        for (int i2 = a[i1]; i2 <= b[i1]; i2++)
        {
            tree[i2] = 1;
        }
    }
    int sum = 0;
    for(i = 0; i < L+1; i++)
    if (tree[i] == 0)
    sum++;
    cout << sum;
    return 0;
    }
