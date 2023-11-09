#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    struct output
    {
        char word;
        int sum;
    } out[26];
    char a[300];
    cin >> a;
    int len = strlen(a);
    int sum1 = 0;
    char ori = 'a';
    int i, j, k;
    for (i = 0; i < 26; i++)
    {
        out[i].word = (char)(ori + i);
        for (j = 0; j < len; j++)
        {
            if (a[j] == (char)(ori + i) || a[j] == (char)(ori + i - 32))
            {
                sum1 += 1;
            }
        }
        out[i].sum = sum1;
        sum1 = 0;
        ori = 'a';
    }
    int temp1, temp2;
    for (i = 0; i < 25; i++)
    {
        for (j = 0; j < 25 - i; j++)
        {
            if (out[j].sum < out[j + 1].sum)
            {
                temp1 = out[j].sum;
                out[j].sum = out[j + 1].sum;
                out[j + 1].sum = temp1;
                temp2 = out[j].            }
        }
    }
}