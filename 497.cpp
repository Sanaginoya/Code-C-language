#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char S[2000];
    char s1[2000];
    char s2[2000];
    cin.getline(S, 2000);
    cin.getline(s1, 2000);
    cin.getline(s2, 2000);
    char* a = strstr(S, s1);
    char* b = S;
    char* temp = S;
    char temp1;
    while (temp != NULL)
    {
        b = temp;
        temp1 = *temp;
        *temp = '\0';
        temp = strstr(temp + 1, s2);
        *b = temp1;
    }
    int Max;
    if (a != NULL)
    {
        Max = strlen(a) - strlen(s1) - strlen(b);
        if (Max > 0)
        cout << Max;
        else
        cout << "-1";
    }
    else
    cout << "-1";
    return 0;
}