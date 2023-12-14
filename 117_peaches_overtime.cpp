#include <iostream>
using namespace std;
int tree[100][100];
int Max = 0;
int Temp = 0;
void get_peaches (int n, int flag, int climb)
{
    if (flag == n)
    {
        Max = (Temp < Max) ? Max : Temp;
        return;
    }
    int i;
    if (flag == 0){
    for (i = 0; i < n; i++)
    {
        Temp += tree[flag][i];
        get_peaches(n, flag + 1, i);
        Temp -= tree[flag][i];
    }
    }
    else
    {
        if (climb - 1 >= 0)
        {
            Temp += tree[flag][climb - 1];
            get_peaches(n, flag + 1, climb - 1);
            Temp -= tree[flag][climb - 1];
        }
        if (climb < n - flag)
        {
            Temp += tree[flag][climb];
            get_peaches(n, flag + 1, climb);
            Temp -= tree[flag][climb];
        }
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    int i, j;
    for (i = n - 1; i >= 0; i--)
    for (j = 0; j < n - i; j++)
    cin >> tree[i][j];
    get_peaches(n, 0, 0);
    cout << Max;
    return 0;
}