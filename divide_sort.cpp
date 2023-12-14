//目前对我来说最难懂的一部分，分治中的归并排序，需要建立强大的递归信心
#include <iostream>
using namespace std;
void merge (int a[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0;
    int b[right - left + 1];
    while ((i <= mid) && (j <= right))
    {
        if (a[i] <= a[j])
        b[k++] = a[i++];
        else if (a[i] > a[j])
        b[k++] = a[j++];
    }
    while(i <= mid)
    b[k++] = a[i++];
    while (j <= right)
    b[k++] = a[j++];
    for (i = left, k = 0; i <= right; i++, k++)
    a[i] = b[k];
}
void divide_sort (int a[], int left, int right)
{
    if (left >= right)
    return;
    int mid = (left + right) / 2;
    divide_sort(a, left, mid);
    divide_sort(a, mid + 1, right);
    merge(a, left, mid, right);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    int i;
    for (i = 0; i < n; i++)
    cin >> a[i];
    divide_sort(a, 0, n - 1);
    for (i = 0; i < n; i++)
    cout << a[i] <<endl;
    return 0;
}