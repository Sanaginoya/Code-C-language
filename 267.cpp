#include <iostream>
#include <stdio.h>
using namespace std;
struct child
{
    char ID[100];
    int month;
    int day;
    int sex;
};
struct week
{
    int monthbeg;
    int daybeg;
    int monthfin;
    int dayfin;
    int number;
    int boy;
};
int main()
{
    int year, flag = 0;
    int start = 3;
    int n, m;
    week weeks[60];
    cin >> year >> n >> m;
    child children[n];
    int i, j;
    for (i = 0; i < 60; i++)
    weeks[i].boy = weeks[i].number = 0;
    for (i = 0; i < n; i++)
    {
        cin >> children[i].ID >> children[i].month >> children[i].day >> children[i].sex;
    }
    for (i = 1969; i < year; i++)
    {
        if (i % 4 == 0)
        start = (start + 365) % 7 + 1;
        else
        start = (start + 364) % 7 + 1;
    }
    weeks[0].monthbeg = 1;
    weeks[0].daybeg = 1;
    if (i % 4 == 0)
    {
        for (i = 1; i <= 12; i++)
        {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            {
                for (j = 1; j <= 31; j++)
                {
                    start = start % 7 + 1;
                    if (start == 7)
                    {
                        weeks[flag].monthfin = i;
                        weeks[flag].dayfin = j;
                        flag++;
                    }
                    if (start == 1)
                    {
                        weeks[flag].monthbeg = i;
                        weeks[flag].daybeg = j;
                    }
                }
            }
            else if (i == 2)
            {
                for (j = 1; j <= 29; j++)
                {
                    start = start % 7 + 1;
                    if (start == 7)
                    {
                        weeks[flag].monthfin = i;
                        weeks[flag].dayfin = j;
                        flag++;
                    }
                    if (start == 1)
                    {
                        weeks[flag].monthbeg = i;
                        weeks[flag].daybeg = j;
                    }
                }
            }
            else if (i == 4 || i == 6 || i == 9 || i == 11)
            {
                for (j = 1; j <= 30; j++)
                {
                    start = start % 7 + 1;
                    if (start == 7)
                    {
                        weeks[flag].monthfin = i;
                        weeks[flag].dayfin = j;
                        flag++;
                    }
                    if (start == 1)
                    {
                        weeks[flag].monthbeg = i;
                        weeks[flag].daybeg = j;
                    }
                }
            }
        }
    }
    else
    {
        for (i = 1; i <= 12; i++)
        {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            {
                for (j = 1; j <= 31; j++)
                {
                    start = start % 7 + 1;
                    if (start == 7)
                    {
                        weeks[flag].monthfin = i;
                        weeks[flag].dayfin = j;
                        flag++;
                    }
                    if (start == 1)
                    {
                        weeks[flag].monthbeg = i;
                        weeks[flag].daybeg = j;
                    }
                }
            }
            else if (i == 2)
            {
                for (j = 1; j <= 28; j++)
                {
                    start = start % 7 + 1;
                    if (start == 7)
                    {
                        weeks[flag].monthfin = i;
                        weeks[flag].dayfin = j;
                        flag++;
                    }
                    if (start == 1)
                    {
                        weeks[flag].monthbeg = i;
                        weeks[flag].daybeg = j;
                    }
                }
            }
            else if (i == 4 || i == 6 || i == 9 || i == 11)
            {
                for (j = 1; j <= 30; j++)
                {
                    start = start % 7 + 1;
                    if (start == 7)
                    {
                        weeks[flag].monthfin = i;
                        weeks[flag].dayfin = j;
                        flag++;
                    }
                    if (start == 1)
                    {
                        weeks[flag].monthbeg = i;
                        weeks[flag].daybeg = j;
                    }
                }
            }
        }
    }
    if (start != 7)
    {
        weeks[flag].monthfin = 12;
        weeks[flag].dayfin = 31;
        flag++;
    }
    for (i = 0; i < n; i++)
    {
        int s1;
        s1 = 100 * children[i].month + children[i].day;
        for (j = 0; j < flag; j++)
        {
            int s2, s3;
            s2 = 100 * weeks[j].monthbeg + weeks[j].daybeg;
            s3 = 100 * weeks[j].monthfin + weeks[j].dayfin;
            if (s1 >= s2 && s1 <= s3)
            {
                weeks[j].number += 1;
                if (children[i].sex == 1) 
                weeks[j].boy += 1;
            }
        }
    }
    week temp;
    for (i = 0; i < flag - 1; i++)                          //冒泡是稳定排序，不必再排
    {
        for (j = 0; j < flag - 1 - i; j++)
        {
            if (weeks[j].number < weeks[j + 1].number)
            {
                temp = weeks[j];
                weeks[j] = weeks[j + 1];
                weeks[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < m; i++)
    {
        cout << "[";
        if (weeks[i].monthbeg < 10)
        cout << " " << weeks[i].monthbeg;
        else
        cout << weeks[i].monthbeg;
        cout << ".";
        if (weeks[i].daybeg < 10)
        cout << " " << weeks[i].daybeg;
        else
        cout << weeks[i].daybeg;
        cout << "-";
        if (weeks[i].monthfin < 10)
        cout << " " << weeks[i].monthfin;
        else
        cout << weeks[i].monthfin;
        cout << ".";
        if (weeks[i].dayfin < 10)
        cout << " " << weeks[i].dayfin;
        else
        cout << weeks[i].dayfin;
        cout << "]:" << weeks[i].number << "(B" << weeks[i].boy << ")" << endl;
    }
    return 0;
}