#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char a[1000001];
    int b[10] = {0};
    cin.getline(a, 1000001);
    int i, flag = 0;
    int j;
    for (i = 0; i < strlen(a); i++)
    {
        if (((int)a[i] >= 48) && ((int)a[i] < 58))
        {
            b[(int)a[i] - 48] += 1;
        }
    }
    for (i = 9; i >= 0; i--)
    for (j = b[i]; j > 0; j--)
    cout << i;
    return 0;
}