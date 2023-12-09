#include <iostream>
using namespace std;
int steps = 0;
int minmin = 0;
int inspect (int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    if (a[i] > a[i + 1])
    return 0;
    return 1;
}
void selection_sort (int a[], int left, int n, int step)
{
    if (inspect(a, n) == 1)
    return;
    minmin = a[left];
    int change = left;
    for (int i = left + 1; i < n; i++)
    {
        if (a[i] < minmin)
        {
            minmin = a[i];
            change = i;
        }
    }
    if (change != left){
    steps++;
    a[change] = a[left];
    a[left] = minmin;
    int b[n];
    for (int i = 0; i < n; i++)
    b[i] = a[i];
    selection_sort (a, left + 1, n, step + 1);
    cout << step << "<->" << change + 1 << ":";
    for (int i = 0; i < n; i++)
    cout << b[i] << " ";
    cout <<endl;
    }
    else
    selection_sort (a, left + 1, n, step + 1);
    return;
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
    selection_sort (a, 0, n, 1);
    cout << "Total steps:" << steps <<endl;
    cout << "Right order:" ;
    for (i = 0; i < n; i++)
    cout << a[i] << " ";
    return 0;
}