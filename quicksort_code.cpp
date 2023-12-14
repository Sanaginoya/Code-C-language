#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int partition (int arr[], int left, int right)
{
    srand((unsigned)time(NULL));
    int Temp = (rand() % (right - left + 1)) + left;
    int temp = arr[Temp];
    arr[Temp] = arr[left];
    arr[left] = temp;
    do
    {
        while ((left < right) && (arr[right] > temp))
        right--;
        if (left < right)
        {
            arr[left] = arr[right];
            left = left + 1;
        }
        while ((left < right) && (arr[left] <= temp))
        left++;
        if (left < right)
        {
            arr[right] = arr[left];
            right = right - 1;
        }
    } while (left != right);
    arr[left] = temp;
    return left;
}
void quicksort (int arr[], int left, int right)
{
    int m = 0;
    if (left >= right)
    return;
    m = partition (arr, left, right);
    quicksort(arr, left, m - 1);
    quicksort(arr, m + 1, right);
    return;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quicksort (a, 0, n - 1);
    for (i = 0; i < n; i++)
    cout << a[i] << endl;
    return 0;
}