#include <iostream>
using namespace std;
int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    int i;
    int arr[n + 1] = {0};
    arr[1] = arr[2] = 1;
    for (i = 3; i < n + 1; i++)
    {
        arr[i] = (a * arr[i - 1] + b * arr[i - 2]) % 7;
    }
    cout << arr[n];
    return 0;
}