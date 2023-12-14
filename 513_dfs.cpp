#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
long long Max = 0;
long long Temp = 0;
long long mathify (char* string)
{
    int len = strlen(string);
    int i;
    long long sum = 0;
    for (i = 0; i < len; i++)
    {
        sum = sum + ((int)(*(string + i)) - 48) * pow(10, len - i - 1);
    }
    return sum;
}
void string_add(char string[], int n, int flag, int strlength, int sign)
{
    int i;
    char temp;
    if (flag == n)
    {
        Max = (Max < Temp) ? Temp : Max;
        return;
    }
    for (i = 0; i < strlength - 1; i++)
    {
        if (i >= sign)
        {
            flag++;
            temp = string[i + 1];
            string[i + 1] = '\0';
            Temp = Temp + mathify(&string[sign]);
            string[i + 1] = temp;
            if (flag == n)
            Temp = Temp + mathify(&string[i + 1]);
            string_add(string, n, flag, strlength, i + 1);
            string[i + 1] = '\0';
            Temp = Temp - mathify(&string[sign]);
            string[i + 1] = temp;
            if (flag == n)
            Temp = Temp - mathify(&string[i + 1]);
            flag = flag - 1;                                 //nescessary
        }
    }
    return;
}
int main()
{
    int n;
    char string[16];
    cin >> n;
    cin.get();
    cin.getline(string, 16);
    int strlength = strlen(string);
    string_add(string, n, 0, strlength, 0);
    cout << Max;
    return 0;
}