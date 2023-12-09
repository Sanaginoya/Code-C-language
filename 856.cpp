#include <iostream>
using namespace std;
int bitsum (int a)
{
    int b[5] = {0};
    int c = a;
    int i = 0;
    while(c)
    {
        b[i++] = c % 10;
        c = c / 10;
    }
    return a + b[0] + b[1] + b[2] + b[3] + b[4];
}
int judge (int a)
{
    int i;
    for (i = (a - 45) < 0 ? 0 : (a - 45); i < a; i++)
    {
        if (bitsum(i) == a)
        return i;
    }
    return 0;
}
int main()
{
    int number[100000] = {0};
    int i = 0;
    do
    {
        cin >> number[i++];
    } while (number[i - 1] != 0);
    int j = 0;
    for (j = 0; j < i - 1; j++)
    {
        cout << judge(number[j]) <<endl;
    }
    return 0;
}