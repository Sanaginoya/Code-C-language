#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int i;
    for(i = 1; i <= a; i++)
    {
        if (a % i == 0)
        cout << i << " ";
    }
    return 0;

}