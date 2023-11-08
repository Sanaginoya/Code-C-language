#include <iostream>
#include <cstring>
using namespace std;
int C (char ori[], int sz)
{
    char a[200];
    cin.get();
    cin.getline(a, 200);
    int sum = 0;
    int sz1 = 0;
    int i = 0, j = 0;
    for (i = 0; a[i] != '\0'; i++)
    {
        sz1++;
    }
    for (i = 0; i < sz; i++)
    {
       for (j = 0; j < sz1; j++)
       {
         if (ori[i + j] != a[j])
         break;
         else
         {
            if (j != sz1 - 1)
            continue;
            else
            {
                i = i + sz1 - 1;    //  易错 ：i在循环中还会再加1，所以这里需要减一个一
                sum++;
            }
         }
       }
    }
    return sum;
}
char* D (char ori[])
{
    char a[200];
    char space[500];
    cin.get();
    cin.getline(a, 200);
    int sz1 = strlen(a);
    char* first = strstr(ori, a);
    if (first == NULL)
    return ori;
    else
    {
        //strcpy(first, first + sz1);   有潜在隐患？
        strcpy(space, first + sz1);
        strcpy(first, space);
        return ori;
    }
}
char* I (char ori[])
{
    char a[200], b[1000];
    cin >> a >> b;
    char* pa = NULL;
    char* answer = NULL;
    int sz1 = strlen(b);
    do
    {
        answer = pa;
        if (pa == NULL)
        pa = ori;
        else
        pa = pa + 1;
        pa = strstr(pa, a);
    }   while (pa != NULL);
    if (answer == NULL)
    {
        return ori;
    }
    else
    {
        strcat(b, answer);
        *answer = '\0';
        strcat(ori, b);
        return ori;
    }
}
char* R (char ori[])
{
    char a[200], b[1000], space[1000];
    cin >> a >> b;
    char c[200];
    memcpy (c, b, 200);
    char* find = ori;
    int sz1 = strlen(a);
    do
    {
        find = strstr(find, a);
        if (find == NULL)
        {
            break;
        }
        else
        {
            strcpy(space, find + sz1);
            strcpy(find, space);
            strcat(b, find);
            *find = '\0';
            strcat(ori, b);
            memcpy(b, c, 200);
        }
    } while (1);
    return ori;
}
int main()
{
    char oristr[500];
    cin.getline(oristr, 500);
    char order;
    cin >> order;
    int s = strlen(oristr);
    switch (order)
    {
        case 'C':
        cout << C(oristr, s)<<endl;
        break;
        case 'D':
        cout << D(oristr)<<endl;
        break;
        case 'I':
        cout << I(oristr)<<endl;
        break;
        case 'R':
        cout << R(oristr)<<endl;
        break;
        default:
        break;
    }
    return 0;
}