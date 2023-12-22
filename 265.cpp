#include <iostream>
using namespace std;
int main()
{
    long long a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    long long i = 1;
    while(1)
    {
        if ((i * a2) % b2 == 0)
        {
            break;
        }
        else
        i++;
    }
    long long c = (i * a2) / b2;
    a1 = a1 * i + c * b1;
    a2 = i * a2;
    if (a1 == a2)
    {
        cout << "1/1";
    }
    else
    {
        long long temp1 = (a1 < a2) ? a2 : a1;
        long long temp2 = (a1 < a2) ? a1 : a2;
        long long temp3 = temp1 % temp2;
        while (temp3 != 0)
        {
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp1 % temp2;
        }
        cout << a1 / temp2 << "/" << a2 / temp2;
    }
    return 0;
}