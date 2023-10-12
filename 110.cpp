#include <iostream>
#include <cstring>
using namespace std;
int judge (char m[], int n)
{
    int i = 0;
    n = n - 1;
    while (i < n)
    {
        if (m[i] == m[n])
        {
            i++;
            n = n - 1;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
int main ()
{
    char a[2000];
    cin >> a;
    int sz = strlen(a);
    if (judge (a, sz) == 1)
    cout << "Yes" <<endl;
    else
    cout << "No" <<endl;
    return 0;
}