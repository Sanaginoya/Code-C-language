#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char row[n][205];
    int a;
    char b[10];
    cin >> b;
    cin >> a;
    int i = 0;
    cin.get();
    for (i = 0; i < n; i++)
    {
        cin.getline(&row[i][0], 205);
    }
    if (*b == 't')
    {
        for (i = n - a; i < n; i++)
        cout << row[i] << endl;
    }
    else if (*b == 'h')
    {
        for (i = 0; i < a; i++)
        cout << row[i] << endl;
    }
    return 0;
}