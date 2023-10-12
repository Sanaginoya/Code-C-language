#include <iostream>
using namespace std;
int main()
{
    int d, h;
    cin >> d >> h;
    int a[32] = {0};
    int i, temp1, temp2;
    int sum = 0;
    for(i = 0;;i++)
    {
        temp1 = d % h;
        temp2 = d / h;
        if (temp2 != 0)
        {
            a[i] = temp1;
            d = temp2;
            sum++;
        }
        else
        {
            a[i] = temp1;
            sum++;
            break;
    }
    }
    for (i = sum - 1 ; i >= 0; i--)
    {
        if (a[i] < 10)
        cout << a[i];
        else if(a[i] == 10)
        cout << 'A';
        else if(a[i] == 11)
        cout << 'B';
        else if(a[i] == 12)
        cout << 'C';
        else if(a[i] == 13)
        cout << 'D';
        else if(a[i] == 14)
        cout << 'E';
        else if(a[i] == 15)
        cout << 'F';
    }
    return 0;
}
