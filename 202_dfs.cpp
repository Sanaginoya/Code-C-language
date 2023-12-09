#include <iostream>
using namespace std;
int way = 0;
int result[5000][10];
struct likebook
    {
        int people;
        char like[10];
    } book[10];
void assignbook(int i, int n, int taken[])
{
    int j, k;
                if (i == n)                                    //递归条件写在既可以写在循环内，也可以写在循环外，但要注意条件有微调
            {
                way++;
                return;
            }
    for (j = 0; j < n; j++)
    {
        if ((taken[j] != 1) && (book[i].like[j] != '0'))
        {
            taken[j] = 1;
            for (k = way; k < 5000; k++)
            result[k][i] = j;
            assignbook(i + 1, n, taken);
            taken[j] = 0;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int taken[n] = {0};
    int i, j;
    for (i = 0; i < n; i++)
    book[n].people = i;
    for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    {
        cin >> book[i].like[j];
    }
    assignbook(0, n, taken);
    if (way != 0){
    cout << way <<endl;
    for (i = 0; i < way; i++)
    {
        for (j = 0; j < n; j++)
        cout << "B" << result[i][j] + 1;
        cout << endl;
    }
    }
    else
    cout << "NO";
    return 0;
}