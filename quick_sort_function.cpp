#include <iostream>
#include <cstdlib>
using namespace std;
int cmp (const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    qsort (a, n, 4, cmp);
    for (i = 0; i < n; i++)
    {
        cout << a[i] <<endl;
    }
    return 0;
}