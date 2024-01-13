#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
char maze[600][600] = {'\0'};
char search[105];
int flag = 0;
int star[100] = {0};
int starsign = 0;
int starrow[100], starcol[100], signnow[100];
char starsymbol[100];
void maze_search (int row, int col, int sign, int len)
{
    char temp;
    if (sign == len)
    {
        flag = 1;
        return;
    }
    if (star[0] == 1)                                //对‘*’的处理
    {
        for (int i = 0; i < starsign; i++)
        {
            maze[starrow[i]][starcol[i]] = starsymbol[i];
        }
    }
    if ((maze[row][col] == search[sign]) || ((int)maze[row][col] == ((int)search[sign] - 32)) || (maze[row][col] == '?') || (maze[row][col] == '*'))
    {
        if (maze[row][col] == '*')                            //对‘*’的处理
        { 
            star[starsign] = 1;
            starrow[starsign] = row;
            starcol[starsign] = col;
            starsymbol[starsign] = search[sign];
            signnow[starsign] = sign;
            starsign++;
        }
        if (maze[row - 1][col - 1] != '\0')                  //八种情况
        {
            temp = maze[row][col];
            maze[row][col] = '\0';
            maze_search(row - 1, col - 1, sign + 1, len);
            if (flag == 1)
            return;
            maze[row][col] = temp;
        }
        if (maze[row - 1][col] != '\0')
        {
            temp = maze[row][col];
            maze[row][col] = '\0';
            maze_search(row - 1, col, sign + 1, len);
            if (flag == 1)
            return;
            maze[row][col] = temp;
        }
        if (maze[row - 1][col + 1] != '\0')
        {
            temp = maze[row][col];
            maze[row][col] = '\0';
            maze_search(row - 1, col + 1, sign + 1, len);
            if (flag == 1)
            return;
            maze[row][col] = temp;
        }
        if (maze[row][col - 1] != '\0')
        {
            temp = maze[row][col];
            maze[row][col] = '\0';
            maze_search(row, col - 1, sign + 1, len);
            if (flag == 1)
            return;
            maze[row][col] = temp;
        }
        if (maze[row][col + 1] != '\0')
        {
            temp = maze[row][col];
            maze[row][col] = '\0';
            maze_search(row, col + 1, sign + 1, len);
            if (flag == 1)
            return;
            maze[row][col] = temp;
        }
        if (maze[row + 1][col - 1] != '\0')
        {
            temp = maze[row][col];
            maze[row][col] = '\0';
            maze_search(row + 1, col - 1, sign + 1, len);
            if (flag == 1)
            return;
            maze[row][col] = temp;
        }
        if (maze[row + 1][col] != '\0')
        {
            temp = maze[row][col];
            maze[row][col] = '\0';
            maze_search(row + 1, col, sign + 1, len);
            if (flag == 1)
            return;
            maze[row][col] = temp;
        }
        if (maze[row + 1][col + 1] != '\0')
        {
            temp = maze[row][col];
            maze[row][col] = '\0';
            maze_search(row + 1, col + 1, sign + 1, len);
            if (flag == 1)
            return;
            maze[row][col] = temp;
        }
        for (int i = 0; i < starsign; i++){
         if (row == starrow[i] && col == starcol[i] && star[i] == 1)              //特别地，对‘*’位置的处理
        {
            temp = maze[row][col];
            maze_search(row, col, sign + 1, len);
            if (flag == 1)
            return;
            maze[row][col] = temp;
        }
        } 
        if (signnow[starsign - 1] == sign && star[starsign - 1] == 1)         //‘*’位置回溯
        {
            star[starsign] = 0;
            starsign--;
        }
    }
}
int main()
{
    int m, n;
    cin >> m >> n;
    cin.get();
    int i, j, k, p, q;
    for(i = 1; i <= m; i++)
    {
        scanf ("%s", &maze[i][1]);             //注意cin和scanf输入的区别
    }
    char ori[105], temp;
    cin.get();
    cin.getline(ori, 105);
    int len = strlen(ori);
    for (i = len; i >= 1; i--)                              //枚举不同长度的串
    {
        for(k = 0, j = i; j <= len; j++, k++)
        {
            temp = ori[j];
            ori[j] = '\0';
            strcpy(search, &ori[k]);
            int lensearch = strlen(search);
            for (p = 1; p <= m; p++)
            {
                for (q = 1; q <= n; q++)
                {
                    maze_search(p, q, 0, lensearch);
                    star[0] = 0;
                    if (flag == 1)
                    goto exit;
                    else
                    continue;
                }
            }
            ori[j] = temp;
        }
    }
    exit:   cout << search;
    return 0;
}