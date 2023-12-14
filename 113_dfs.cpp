#include <iostream>
#include <cstring>
using namespace std;
int answer = 0;
void chess (int n, int flag, int board[12][12])
{
    int i, j, k;
    if (flag == n){
        answer += 1;
        return;
    }
    for (i = 0; i < n; i++)                  //回溯过程不回头
    {
        if (board[flag][i] == 0)
        {
            for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
            {
                if (((k + j == flag + i) && (j != flag)) || ((j - k == flag - i) && (j != flag)) || (j == flag) || (j != flag) && (k == i))
                board[j][k] += 1;
            }
            chess(n, flag + 1, board);
            for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
            {
                if (((k + j == flag + i) && (j != flag)) || ((j - k == flag - i) && (j != flag)) || (j == flag) || (j != flag) && (k == i))
                board[j][k] -= 1;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int board[12][12];
    memset(board, 0, 576);
    if (n > 3){
    chess(n, 0, board);
    cout << answer;
    }
    else if (n == 1)
    cout << "1";
    else if (n == 2 || n == 3)
    cout << "0";
    return 0;
}