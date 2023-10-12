#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char A = 'A';
    int i = 1;
    int j = 1;
    int m = 1;
    int p = 1;
    int q = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n-i; j++)
        {
            cout << " ";
        }
        cout << A;
        for (p = 1; p < i; p++)
        {
            A = A + 1;
            cout << A;
        }
        for (q = 1; q < i; q++)
        {
            A = A - 1;
            cout << A;
        }
        for (m = 1; m <= n-i; m++)
        {
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}