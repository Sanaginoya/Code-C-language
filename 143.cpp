#include <iostream>
using namespace std;
int a[10] = {0};
int taken[11] = {0};
int SUM = 0;
int flag = 0;
int C (int high, int low)
{
    int i = 0;
    int a1 = 1;
    int a2 = 1;
    while (i != high)
    {
        a1 *= low--;
        i++;
    }
    while (high >= 1)
    {
        a2 *= high--;
    }
    return a1 / a2;
}
void arrange (int n, int sum)
{   
    if (flag == n)
    {
        return;
    }
    int i;
    for (i = 1; i <= n; i++)
    {
        if (taken[i] == 0)
        {
            a[flag] = i;
            taken[i] = 1;
            SUM = SUM + C(flag, n - 1) * i;
            flag++;
            arrange(n, sum);
            if ((SUM == sum) && (flag == n)){
            return;
            }
            else{
            flag -= 1;
            a[flag] = 0;
            SUM = SUM - C(flag, n - 1) * i;
            taken[i] = 0;
            }
        }
    }
}
int main()
{
    int n, sum;
    cin >> n >> sum;
    if (n > 2){
    arrange(n, sum);
    int i;
    for (i = 0; i < n; i++)
    cout << a[i] << " ";
    }
    else if ((n == 1) && (sum == 1))
    cout << "1";
    else if ((n == 2) && (sum == 3))
    cout << "1 2";
    return 0;
}