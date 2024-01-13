#include <stdio.h>
#include <stdlib.h>
using namespace std;
int cmp (const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n], b[n], c[n], d[n];
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        d[i] = a[i] + b[i] + c[i];
    }
    qsort (d, n, 4, cmp);
    for (i = 0; i < n; i++)
    {
        printf("%d\n", d[i]);
    }
    return 0;
}