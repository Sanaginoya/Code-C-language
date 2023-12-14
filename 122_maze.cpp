#include <iostream>
#include <cstring>
using namespace std;
int judge = 0;
void maze (int map[11][11], int row, int col, int rsign, int csign, int sign)
{
    if((rsign == row) && (csign == col)){
    judge += 1;
    return;
    }
    if((map[rsign + 1][csign] == 1) && (sign != 3))
    {
        rsign = rsign + 1;
        maze(map, row, col, rsign, csign, 1);
        rsign = rsign - 1;
    }
    if((map[rsign][csign + 1] == 1) && (sign != 4))
    {
        csign = csign + 1;
        maze(map, row, col, rsign, csign, 2);
        csign = csign - 1;
    }
    if((map[rsign - 1][csign] == 1) && (sign != 1))
    {
        rsign = rsign - 1;
        maze(map, row, col, rsign, csign, 3);
        rsign = rsign + 1;
    }
    if((map[rsign][csign - 1] == 1) && (sign != 2))
    {
        csign = csign - 1;
        maze(map, row, col, rsign, csign, 4);
        csign = csign + 1;
    }
    return;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int map[11][11];
    memset(map, 0, 484);
    int i, j;
    for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
    cin >> map[i][j];
    maze(map, n, m, 1, 1, 0);
    if (judge)
    cout << "YES";
    else
    cout << "NO";
    return 0;
}