#include <iostream>
#include <cmath>
using namespace std;
int min_result (int a, int b)
{
    return (a > b)? b: a;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int i , j;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int min = abs(arr[0] - arr[1]);
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if ((i != 0) && (j != 1))
            min = min_result(min, abs(arr[i] - arr[j]));
        }
    }
    cout << min;
    return 0;
}