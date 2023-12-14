#include <iostream>
using namespace std;
int Temp = 0;
int Max = -101;
void maze(int map[10][10], int row, int col, int rsign, int csign)
{
    int temp;
    if ((rsign == 1) && (csign == col))
    {
        Max = (Max < Temp) ? Temp : Max;
        return;
    }
    if (map[rsign - 1][csign] != 1000)
    {
        Temp += map[rsign - 1][csign];
        temp = map[rsign][csign];
        map[rsign][csign] = 1000;
        rsign = rsign - 1;
        maze(map, row, col, rsign, csign);
        rsign = rsign + 1;
        map[rsign][csign] = temp;
        Temp -= map[rsign - 1][csign];
    }
    if (map[rsign][csign + 1] != 1000)
    {
        Temp += map[rsign][csign + 1];
        temp = map[rsign][csign];
        map[rsign][csign] = 1000;
        csign = csign + 1;
        maze(map, row, col, rsign, csign);
        csign = csign - 1;
        map[rsign][csign] = temp;
        Temp -= map[rsign][csign + 1];
    }
    if (map[rsign][csign - 1] != 1000)
    {
        Temp += map[rsign][csign - 1];
        temp = map[rsign][csign];
        map[rsign][csign] = 1000;
        csign = csign - 1;
        maze(map, row, col, rsign, csign);
        csign = csign + 1;
        map[rsign][csign] = temp;
        Temp -= map[rsign][csign - 1];
    }
    return;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int map[10][10];
    int i, j;
    for (i = 0; i < 10; i++)
    for (j = 0; j < 10; j++)
    map[i][j] = 1000;
    for (i = n; i >= 1; i--)
    for (j = 1; j <= m; j++)
    cin >> map[i][j];
    Temp = map[n][1];
    maze(map, n, m, n, 1);
    cout << Max;
    return 0;
}