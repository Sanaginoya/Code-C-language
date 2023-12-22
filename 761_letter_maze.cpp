#include <iostream>
#include <cstring>
using namespace std;
char search[105];
char maze[600][600];
void solve (int row, int col, int rsign, int csign, int flag)
{
    if ((maze[row][col] == search[flag] || maze[row][col] == '?' || ((int)maze[row][col] - 32 == (int)search[flag])) && (row <= rsign) && (col <= csign))
    {
        if (maze[row - 1][col - 1] != '0')
        {
            char temp;
            temp = maze[row][col];
            maze[row][col] = '0';
            solve (row - 1, col - 1, rsign, csign, flag + 1);
            maze[row][col] = temp;
        }
        if (maze[row - 1][col] != '0')
        {
            char temp;
            temp = maze[row][col];
            maze[row][col] = '0';
            solve (row - 1, col, rsign, csign, flag + 1);
            maze[row][col] = temp;
        }
        if (maze[row - 1][col + 1] != '0')
        {
            char temp;
            temp = maze[row][col];
            maze[row][col] = '0';
            solve (row - 1, col + 1, rsign, csign, flag + 1);
            maze[row][col] = temp;
        }
        if (maze[row][col - 1] != '0')
        {
            char temp;
            temp = maze[row][col];
            maze[row][col] = '0';
            solve (row, col - 1, rsign, csign, flag + 1);
            maze[row][col] = temp;
        }
        if (maze[row][col + 1] != '0')
        {
            char temp;
            temp = maze[row][col];
            maze[row][col] = '0';
            solve (row, col + 1, rsign, csign, flag + 1);
            maze[row][col] = temp;
        }
        if (maze[row + 1][col - 1] != '0')
        {
            char temp;
            temp = maze[row][col];
            maze[row][col] = '0';
            solve (row + 1, col - 1, rsign, csign, flag + 1);
            maze[row][col] = temp;
        }
        if (maze[row + 1][col] != '0')
        {
            char temp;
            temp = maze[row][col];
            maze[row][col] = '0';
            solve (row + 1, col, rsign, csign, flag + 1);
            maze[row][col] = temp;
        }
        if (maze[row + 1][col + 1] != '0')
        {
            char temp;
            temp = maze[row][col];
            maze[row][col] = '0';
            solve (row + 1, col + 1, rsign, csign, flag + 1);
            maze[row][col] = temp;
        }
    }
    else
    {
        if (row < rsign)
        row++;
        else
        {
            row = 1;
            if(col < csign)
            col++;
            else
            {
                return;
            }
        }
    }
}
int main()
{
    int m, n;
    cin >> m >> n;
    memset(maze, 48, 600 * 600);
    int i, j;
    for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++)
    cin >> maze[i][j];
    cin.getline(search, 105);
    solve(1, 1, m, n, 0);
    return 0;
}