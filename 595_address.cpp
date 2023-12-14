#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
void str1 (int i, int j, int k, char str[], int length)
{
    int t;
    for (t = length; t >= i; t--)
    str[t + 1] = str[t];
    str[i] = '.';
    for (t = length + 1; t >= j + 1; t--)
    str[t + 1] = str[t];
    str[j + 1] = '.';
    for (t = length + 2; t >= k + 2; t--)
    str[t + 1] = str[t];
    str[k + 2] = '.';
    cout << str << endl;
    return;
}
int main()
{
    char ip[20];
    cin.getline(ip, 20);
    int i, j, k;
    long long a = 0;
    int length = strlen(ip);
    char temp1, temp2, temp3;
    for (i = 1; i < length - 1; i++)
    {
        for (j = i + 1; j < length - 1; j++)
        {
            for (k = j + 1; k < length; k++)
            {
                temp1 = ip[i];
                ip[i] = '\0';
                sscanf(ip, "%lld", &a);
                if (((ip[0] != '0') && (strlen(ip) > 1) && (a <= 255)) || (strlen(ip) == 1))
                {
                    ip[i] = temp1;
                    temp2 = ip[j];
                    ip[j] = '\0';
                    sscanf(&ip[i], "%lld", &a);
                    if (((ip[i] != '0') && (strlen(&ip[i]) > 1) && (a <= 255)) || (strlen(&ip[i]) == 1))
                    {
                        ip[j] = temp2;
                        temp3 = ip[k];
                        ip[k] = '\0';
                        sscanf(&ip[j], "%lld", &a);
                        if (((ip[j] != '0') && (strlen(&ip[j]) > 1) && (a <= 255)) || (strlen(&ip[j]) == 1))
                        {
                            ip[k] = temp3;
                            sscanf(&ip[k], "%lld", &a);
                            if (((ip[k] != '0') && (strlen(&ip[k]) > 1) && (a <= 255)) || (strlen(&ip[k]) == 1))
                            {
                                char b[20];
                                memcpy(b, ip, 20);
                                str1(i , j , k , b, length);
                            }
                        }
                        else
                        {
                            ip[k] = temp3;
                        }
                        
                    }
                    else
                    {
                        ip[j] = temp2;
                    }
                    
                }
                else
                ip[i] = temp1;
            }
        }
    } 
    return 0;
}