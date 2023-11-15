#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <stdio.h>
using namespace std;
struct phase1                              //定义放在前面
    {
        int ceil;
        int floor;
    };
void task1 (int gra[], struct phase1* pha, int phase)
{
    for (int i = 0; i < phase ; i++)
    {
        if (gra[i] == 0)
        break;
        else
        {
            if ((pha + i)->ceil == 100)
            printf("[%2d,%3d]: %d\n", (pha + i)->floor, (pha + i)->ceil, gra[i]);
            else
            printf("[%2d,%3d): %d\n", (pha + i)->floor, (pha + i)->ceil, gra[i]);
        }
    }
}
void task2 (int grad[], int phas)
{
    int max;
    max = grad[0];
    for (int i = 0; i < phas; i++)
    {
        if(max < grad[i])
        max = grad[i];
    }
    if (max <= 50)
    {
        for (int i = 0; i < phas; i++)
        {
            if (i == phas - 1)
            printf("[%2d,%3d]:", i * (100 / phas), (i + 1) * (100 / phas));
            else
            printf("[%2d,%3d):", i * (100 / phas), (i + 1) * (100 / phas));
            for (int j = 0; j < grad[i]; j++)
            cout << "*";
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < phas; i++)
        {
            if (i == phas - 1)
            printf("[%2d,%3d]:", i * (100 / phas), (i + 1) * (100 / phas));
            else
            printf("[%2d,%3d):", i * (100 / phas), (i + 1) * (100 / phas));
            for (int j = 0; j < floor(50 * (grad[i] / (double)max)); j++)          // Very easy to make a mistake! You need to convert int to double.
            cout << "*";
            cout <<endl;
        }
    }
}
int main()
{
    int n, m, g;
    cin >> n >> m >> g;
    int grade[n];
    int i = 0;
    int j = 0;
    for(i = 0; i < n; i++)
    {
        cin >> grade[i];
    }
    int number[m] = {0};
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (grade[i] == 100)
            {
                number[m - 1] += 1;
                break;
            }
            if (j * (100 / m) <= grade[i] && grade[i] < (j + 1) * (100 / m))
            {
                number[j] += 1;
                break;
            }
        }
    }
    int copy[m];
    memcpy(copy, number, 4*m);
    int temp1 = 0, temp2 = 0, temp3 = 0;
    struct phase1 phase[m];
    for (j = 0; j < m; j++)
    {
        phase[j].ceil = (j + 1) * (100 / m);
        phase[j].floor = j * (100 / m);
    }
    for (i = 0; i < m - 1; i++)
    {
        for (j = 0; j < m - 1 - i; j++)
        {
            if (number[j] < number[j + 1])
            {
                temp1 = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp1;
                temp2 = phase[j].ceil;
                phase[j].ceil = phase[j + 1].ceil;
                phase[j + 1].ceil = temp2;
                temp3 = phase[j].floor;
                phase[j].floor = phase[j + 1].floor;
                phase[j + 1].floor = temp3;
            }
            else if (number[j] == number[j + 1])
            {
                if (phase[j].ceil > phase[j + 1].ceil)
                {
                     temp2 = phase[j].ceil;
                     phase[j].ceil = phase[j + 1].ceil;
                     phase[j + 1].ceil = temp2;
                     temp3 = phase[j].floor;
                     phase[j].floor = phase[j + 1].floor;
                     phase[j + 1].floor = temp3;
                }
            }
        }
    }
    switch (g)
    {
        case 0:
        task1(number, phase, m);
        cout <<endl;
        task2(copy, m);
        break;
        case 1:
        task1(number, phase, m);
        break;
        case 2:
        task2(copy, m);
        break;
        default:
        break;
    }
    return 0;
}