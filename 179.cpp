#include <iostream>
using namespace std;
int main()
{
    int i1 = 0, i2 = 0, i3 = 0;
    int n;
    cin >> n;
    for (i1 = 0; i1 < n - 1; i1++)
    cout << " ";
    for (i1 = 0; i1 < n; i1++)
    cout << '*';
    for (i1 = 0; i1 < n - 1; i1++)
    cout << " " ;
    cout <<endl;
    for (i2 = 1; i2 < n; i2++)
    {
        for (i1 = 0; i1 < n - 1 - i2; i1++)
        cout << " ";
        cout << '*';
        for (i1 = 0; i1 < n + (2 * (i2 - 1)); i1++)
        cout << " ";
        cout << '*';
        for (i1 = 0; i1 < n - 1 - i2; i1++)
        cout << " ";
        cout <<endl;
    }
    for (i3 = 1; i3 < n - 1; i3++)
    {
        for (i1 = 0; i1 < i3; i1++)
        cout << " ";
        cout << '*';
        for (i1 = 0; i1 < n + 2 * (n - 2 - i3); i1++)
        cout << " ";
        cout << '*';
        for (i1 = 0; i1 < i3; i1++)
        cout << " ";
        cout << endl;
    }
    for (i1 = 0; i1 < n - 1; i1++)
    cout << " ";
    for (i1 = 0; i1 < n; i1++)
    cout << '*';
    for (i1 = 0; i1 < n - 1; i1++)
    cout << " ";
    return 0;
}
   