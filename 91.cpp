#include <iostream>
#include <cstring>
using namespace std;
void sta (int f[], int fre[], int len)
{
    int i1, j1;
    for (i1 = 0; i1 < len; i1++)
    {
        for (j1 = 0; j1 < 16; j1++)
        {
            if (f[i1] <= (((j1 + 1) * 16) - 1) && f[i1] >= j1 * 16)
            {
                fre[j1] += 1;
                break;
            }
        }
    }
}
int formula (int orif[], int sf[])
{
    int sum = 0;
    for (int i2 = 0; i2 < 16; i2++)
    {
        sum += (orif[i2] - sf[i2]) * (orif[i2] - sf[i2]);
    }
    return sum;
}
int main()
{
    int length;
    cin >> length;
    int f[length] = {0};
    int i, j;
    for (i = 0; i < length; i++)
    {
        cin >> f[i];
    }
    int orifre[16] = {0};
    sta(f, orifre, length);
    int amount, search;
    cin >> amount >> search;
    int slen;
    int sfre[16] = {0};
    int fin[amount][2];
    memset (fin, 0, 8 * amount);
    for (i = 0; i < amount; i++)
    {
        cin >> slen;
        int sf[slen] = {0};
        for (j = 0; j < slen; j++)
        {
            cin >> sf[j];
        }
        sta (sf, sfre, slen);
        fin[i][0] = i;
        fin[i][1] = formula(orifre, sfre);
        memset(sfre, 0, 64);
    }
    int temp1, temp2;
    for (i = 0; i < amount - 1; i++)
    {
        for (j = 0; j < amount - 1 - i; j++)
        {
            if (fin[j][1] > fin[j + 1][1])
            {
                temp1 = fin[j][1];
                fin[j][1] = fin[j + 1][1];
                fin[j + 1][1] = temp1;
                temp2 = fin[j][0];
                fin[j][0] = fin[j + 1][0];
                fin[j + 1][0] = temp2;            
            }
            if (fin[j][1] == fin[j + 1][1])
            {
                if (fin[j][0] > fin[j + 1][0])                      //记得加大括号。。
                {
                    temp1 = fin[j][0];
                   fin[j][0] = fin[j + 1][0];
                   fin[j + 1][0] = temp1;
                }
            }
        }
    }
    for (i = 0; i < search; i++)
    {
        cout << fin[i][0] << " ";
    }
    return 0;
}