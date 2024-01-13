#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    char str[1100];
    cin.getline(str, 1100);
    int i, j = 1;
    long long sum = 0;
    for (i = 0; i < strlen(str); i++)
    {
        if ((int)str[i] >= 48 && (int)str[i] <= 57)
        {
            while ((int)str[i + j] >= 48 && (int)str[i + j] < 58)
            {
                j++;
            }
            int temp = i + j;
            while (i < temp)
            {
                sum += ((int)str[i] - 48) * pow(10, temp - 1 - i);
                i++;
            }
            j = 1;
        }
    }
    cout << sum;
    return 0;
}