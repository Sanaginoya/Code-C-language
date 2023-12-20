#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char a = 'A';
    if (n < 10)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                cout << " ";
            }
            for (int k = 0; k < 2 * (n - i) - 1; k++)
            cout << n;
            cout <<endl;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                cout << " ";
            }
            for (int k = 0; k < 2 * (n - i) - 1; k++)
            cout << (char)((int)a + (n - 10));
            cout <<endl;
    }
    }
    return 0;
}