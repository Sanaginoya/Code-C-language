#include <iostream>
using namespace std;
/* int binary_search(int a[], int b, int n)
{
    int left = 0, right = n - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid] == b)
        return 1;
        else if (a[mid] < b)
        left = mid + 1;
        else
        right = mid - 1;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    int i = 0, j = 0;
    int temp;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    int b;
    cin >> b;
    if (binary_search(a, b, n) == 1)
    {
        cout << "YES";
    }
    else
    cout << "NO";
    return 0;
} */
//上面是传统二分查找，下面尝试用分治实现
int recursion_binary_search (int a[], int b, int left, int right);
int main()
{
    int n;
    cin >> n;
    int a[n];
    int i = 0, j = 0;
    int temp;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    int b;
    cin >> b;
    if (recursion_binary_search(a, b, 0, n - 1) == 1)
    {
        cout << "YES";
    }
    else
    cout << "NO";
    return 0;
}
int recursion_binary_search (int a[], int b, int left, int right)
{
    int mid = (left + right) / 2;
    if (left <= right)
    {
        if (a[mid] == b)
        return 1;
        else if (a[mid] < b)
        recursion_binary_search(a, b, mid + 1, right);
        else
        recursion_binary_search(a, b, left, mid - 1);
    }
    else
    return 0;
}
