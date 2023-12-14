#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
char* checkSubstr (char s1[], char s2[])
{
    int a[26] = {0};
    int i, j, flag = 0;
    for (i = 0; i < strlen(s1); i++)
    {
        j = (int)s1[i] - 97;
        a[j]++;
    }
    int a1[26];
    memcpy(a1, a, 104);
    char* p = s2;
    while (strlen(p) >= strlen(s1))
    {
        char* p1 = p;
        for (i = 0; i < strlen(s1); i++)
        {
            if (a1[(int)*(p + i) - 97] > 0)
            {
                a1[(int)*(p + i) - 97] -= 1;
                p1++;
                flag++;
            }
            else
            break;
            if (flag == strlen(s1))
            return p;
        }
        p++;
        memcpy(a1, a, 104);
        flag = 0;
    }
    return NULL;
}

int main()
{
    char s1[220], s2[220];
    char *pRes = NULL;

    scanf("%s%s", s1, s2);
    pRes = checkSubstr(s1, s2);

    if ( pRes == NULL )
        printf("false\n");
    else{
        pRes[ strlen(s1) ] = '\0';
        printf("%s", pRes);
    }
    return 0;
}