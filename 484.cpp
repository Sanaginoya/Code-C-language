#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long a[n];
    int i, j, k = 0;
    struct q
    {
        long long number;
        int sum;
    } fin[n];
    for (i = 0; i < n; i++)
    {
        fin[i].number = 1000000000000;
        fin[i].sum = 1;
    }
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i] != 10000000000)
            {
                if (a[i] == a[j] && i != j)
            {
                fin[k].number = a[i];
                fin[k].sum++;
                a[j] = 10000000000;
            }
            }
        }
        k++;
    }
    long long temp1, temp2;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {           
                if (fin[j].number > fin[j + 1].number)
                {
                    temp2 = fin[j].number;
                    fin[j].number = fin[j + 1].number;
                    fin[j + 1].number = temp2;
                    temp1 = fin[j].sum;
                    fin[j].sum = fin[j + 1].sum;
                    fin[j + 1].sum = temp1;
                }
            }
        }
    int flag = 0;
    for (i = 0; i < n; i++)
    {
        if (fin[i].sum > 1)
        {
            cout << fin[i].number << ":" << fin[i].sum <<endl;
            flag = 1;
        }
        else
        {
            break;
        }
        
    }
    if (flag == 0)
    cout << "NO";
    return 0;
}