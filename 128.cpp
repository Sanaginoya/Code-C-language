#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int total, pass;
    cin >> total >> pass;
    struct student
    {
        int id;
        int grade;
    };
    typedef struct student stu;
    stu s[total];
    int i, j, k, n;
    int flag = 0;
    for (i = 0; i < total; i++)
    {
        cin >> s[i].id >> s[i].grade;
    }
    int temp1, temp2;
    for (i = 0; i < total - 1; i++)
    {
        flag = 0;
        for (j = 0; j < total - 1 - i; j++)
        {
            if (s[j].grade < s[j + 1].grade)
            {
                temp1 = s[j].grade;
                s[j].grade = s[j + 1].grade;
                s[j + 1].grade = temp1;
                temp2 = s[j].id;
                s[j].id = s[j + 1].id;
                s[j + 1].id = temp2;
                flag = 1;
            }
        }
        if (flag == 0)
        break;
    }
    int prepass = 0, std;
    std = s[(int)(floor(pass * 1.5) - 1)].grade;    //数组下标必须以整数形式储存，否则无法编译。
    while (std <= s[prepass].grade)
    prepass++;
    flag = 0;
    for (i = 0; i < prepass - 1; i++)
    {
        n = 0;
        if (s[i].grade == s[i + 1].grade)
        {
            flag++;
            if (i != prepass - 2)
            continue;
            else
            {
                i++;           //需要加一来矫正
                goto sort;
            }
        }
sort:   if (flag != 0)
        {
            for (j = i - flag; j < i; j++)
            {
                for (k = i - flag; k < i - n; k++)
                {
                    if (s[k].id > s[k + 1].id)
                    {
                        temp1 = s[k].id;
                        s[k].id = s[k + 1].id;
                        s[k + 1].id = temp1;
                    }
                }
                n++;
            }
            flag = 0;
        }
    }
    cout << std << " " << prepass <<endl;
    for (i = 0; i < prepass; i++)
    {
        cout << s[i].id << " " << s[i].grade <<endl;
    }
    return 0;
}