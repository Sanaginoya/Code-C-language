#include <iostream>
#include <cstdlib>
using namespace std;
int cmp(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b)
    {
        return 1;
    }
    else if (*(int*)a == *(int*)b)
    {
        return 0;
    }
    else
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    cin >> a[i];
    qsort(a,n,4,cmp);
    for (int j = 0; j<n; j++)
    cout << a[j] <<" ";
    return 0;
}