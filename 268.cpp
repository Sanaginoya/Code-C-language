#include <iostream>
using namespace std;
long long minn = 100000000000;
long long temp = 0;
int map[60][60];
int route[500];
int temproute[500];
int city[52] = {0};
void search(int sou, int des, int n, int flag)
{
    if (temp >= minn)
    return;
    if (sou == des)
    {
        for (int i = 0; i < flag; i++)
        route[i] = temproute[i];
        for (int i = flag; i < 500; i++)
        if (route[i] != -1)
        route[i] = -1;
        else
        break;
        minn = temp;
        return;
    }
    int i;
    for (i = 0; i < n; i++)
    {
        if (map[sou][i] != -1 && city[i] != 1)
        {
            city[i] = 1;
            temp += map[sou][i];
            temproute[flag] = i;
            search(i, des, n, flag + 1);
            city[i] = 0;
            temp -= map[sou][i];
            temproute[flag] = -1;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int des, sou;
    cin >> sou >> des;
    int i, j;
    for (i = 0; i < 60; i++)
    {
        for (j = 0; j < 60; j++)
        map[i][j] = -1;
    }
    city[sou] = 1;
    for (i = 0; i < 500; i++)
    route[i] = temproute[i] = -1;
    for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    cin >> map[i][j];
    search(sou, des, n, 0);
    for (i = 0; ; i++)
    {
        if (route[i] != -1)
        {
            if(i == 0)
            cout << sou << "->" << route[i];
            else
            cout << "->" << route[i];
        }
        else
        {
            if (i == 0)
            {
                cout << "-1";
            }
            break;
        }
    }
    return 0;
}