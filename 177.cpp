#include <iostream>
using namespace std;
void Bubble_sort (int a1[], int n1)
{
    int i1, i2;
    int temp = 0;
    int flag = 0;
    for (i1 = 0; i1 < n1 - 1; i1++)
    {
        for (i2 = 0; i2 < n1 - 1 - i1; i2++)
        {
            if(a1[i2] < a1[i2 + 1])
            {
                temp = a1[i2];
                a1[i2] = a1[i2 + 1];
                a1[i2 + 1] = temp;
                flag ++;
            }
        }
        if (flag == 0)
        break;
        else
        flag = 0;
    }
}
int main()
{
    int n, k;
    int i = 0;
    cin >> n >> k;
    int a[n];
    int b[n] = {0};
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = 0;
    int bitsum = 0;
    for (i = 0; i < n; i++)
    {
        bitsum = a[i] % 10 + a[i] / 10 % 10 + a[i] / 100 % 10 + a[i] / 1000 % 10 + a[i] / 10000 % 10 + a[i] / 100000 % 10 + a[i] / 1000000 % 10 + a[i] / 10000000 % 10 +  a[i] / 100000000 % 10 + a[i] / 1000000000;
        if (bitsum % k == 0)
        {
            b[i] = a[i];
            sum++;
        }
    }
    Bubble_sort (b, n);
    cout << sum <<endl;
    for (i = sum - 1; i >= 0; i--)
        cout << b[i] <<endl;
    return 0;
}