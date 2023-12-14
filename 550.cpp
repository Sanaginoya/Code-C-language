#include <iostream>
#include <cstdlib>
using namespace std;
int cmp (const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}
int mid_search (int a[], int left, int right, int goal)
{
    if (left > right)
    return 0;
    int mid = (left + right) / 2;
    if (a[mid] == goal)
    return 1;
    else if (a[mid] > goal)
    return mid_search(a, left, mid - 1, goal);
    else if (a[mid] < goal)
    return mid_search(a, mid + 1, right, goal);
}
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    int i, j, k, p;
    for (i = 0; i < n; i++)
    cin >> a[i];
    qsort(a, n, 4, cmp);
    int flag = 0;
    for (i = 0; i < n - 2; i++)
    {
        if (a[i] < m){
        for (j = i + 1; j < n - 1; j++)
        {
            if (a[i] + a[j] < m){
            for (k = j + 1; k < n; k++)
            {
                if (a[i] + a[j] + a[k] <= m){
                    if (mid_search(a, k + 1, n - 1, m - a[i] - a[j] - a[k]) == 1)
                    flag++;
                }
            }
        }
        }
        }
    }
    cout << flag;
    return 0;
}