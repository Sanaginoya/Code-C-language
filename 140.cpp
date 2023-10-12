#include <iostream>
#include <cstring>
using namespace std;
char* my_strstr(char* a1, char* b1)
{
    int i = 0;
    char* p = NULL;
    int temp = 0;
    for (i = 0; *(a1 + i) != '\0'; i++)  // \0要加单引号表示字符串结束。
    {
        temp = 0;
        for (int j1 = 0, j2 = 0; (*(a1 + i + j2) != '\0') && (*(b1 + j1) != '\0'); j1++, j2++)
        {
            if (*(a1 + i + j2) == *(b1 + j1))
            {
                temp ++;
                if (temp == strlen(b1))
                {
                    p = a1 + i;
                    return p;
                }
            }
            else 
            {
                break;
            }
        }
    }
    return NULL;  
}
int main()
{
    char a[300];
    cin.get(a , 300);
    cin.get();
    char b[9] = "born in ";
    char c[13] = "My major is ";
    char* bir = my_strstr(a, b);
    char* maj = my_strstr(a, c);
    for (int i = 0; i < 4; i++)
    {
        cout << *(bir + 8 + i);
    }
    cout << ", ";
    int i1 = 0;
    while(*(maj + 12 + i1) != '.')
    {
        cout << *(maj + 12 + i1);
        i1++;
    }
    return 0;
}