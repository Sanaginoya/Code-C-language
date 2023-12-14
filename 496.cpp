#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int length[n];
    int arr[n][1000];
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        cin >> length[i];
        for (j = 0; j < length[i]; j++)
        cin >> arr[i][j];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < length[i] - 1; j++){
        if (arr[i][j] < arr[i][j + 1])
        continue;
        else
        {
            for (k = 0; k < j + 1; k++)
            cout << arr[i][k] << " ";
        }
        cout <<endl;
        goto exit;
        }
        cout << "YES" <<endl;
exit:        continue;
    }
    return 0;
}