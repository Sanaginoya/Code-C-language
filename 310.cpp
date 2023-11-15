#include <iostream>
using namespace std;
int judge (int i1)
{
    int temp = i1;
    i1 = i1 * temp;
    while (1)
    {
        if (i1 % 10 == temp % 10 && temp != 0)
        {
            i1 = i1 / 10;
            temp = temp / 10;
        }
        else if (temp == 0)
        return 1;
        else if (i1 % 10 != temp % 10 && temp != 0)
        return 0;
    }
}
int main()
{
    int sum = 0;
    int a, b;
    cin >> a >> b;
    int i = 0;
    for (i = a; i <= b; i++)
    {
        if (judge(i) == 1)
        sum += i;
    }
    cout << sum;
    return 0;
}