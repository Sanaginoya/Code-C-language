#include <iostream>
using namespace std;
int map[10][10] = {0};
int Temp = 0;
int steps = 20;
void method (int row, int col, int goal)
{
    if (Temp >= steps)                       //简化代码的重要一步。
    return;
    if ((row == goal) && (col == goal))
    {
        steps = (steps < Temp) ? steps : Temp;
        return;
    }
    int i = 0, temp = 0;
        for (i = 1; i <= map[row][col]; i++)
        {
            if ((map[row + i][col] != 0) && (row + i <= goal))
            {
                temp = map[row][col];
                map[row][col] = 0;
                Temp++;
                method(row + i, col, goal);
                Temp--;
                map[row][col] = temp;
            }
            if ((map[row - i][col] != 0) && (row - i >= 0))
            {
                temp = map[row][col];
                map[row][col] = 0;
                Temp++;
                method(row - i, col, goal);
                Temp--;
                map[row][col] = temp;
            }
            if ((map[row][col + i] != 0) && (col + i <= goal))
            {
                temp = map[row][col];
                map[row][col] = 0;
                Temp++;
                method(row, col + i, goal);
                Temp--;
                map[row][col] = temp;
            }
            if ((map[row][col - i] != 0) && (col - i >= 0))
            {
                temp = map[row][col];
                map[row][col] = 0;
                Temp++;
                method(row, col - i, goal);
                Temp--;
                map[row][col] = temp;
            }
        }
    }
int main()
{
    int n;
    cin >> n;
    int i, j;
    for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    cin >> map[i][j];
    method(0, 0, n - 1);
    cout << steps;
    return 0;
}