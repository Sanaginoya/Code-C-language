#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
char* convert (char* op, char* in, char* out, char temp[])
{
    int inlen = strlen(in);
    int oplen = strlen(op);
    int outlen = strlen(out);
    int temp1 = 0;
    int i, j, k = 0;
    for (i = oplen - 1; i >= 0; i--)
    {
        for (j = 0; j < inlen; j++)
        {
            if (in[j] == op[i])
            {
                temp1 += j * pow(inlen, oplen - 1 - i);
            }
        }
    }
    int before[35];
    while(temp1)
    {
        before[k] = temp1 % outlen;
        temp1 = temp1 / outlen;
        k++;
    }
    for (i = k - 1; i >= 0; i--)
    {
        temp[k - 1 - i] = out[before[i]];
    }
    return temp;
}
int main()
{
    int n;
    cin >> n;
    char in[n][100];
    char out[n][100];
    char op[n][40];
    int i, j;
    for (i = 0; i < n; i++)
    cin >> op[i] >> in[i] >> out[i];       //允许这种输入方法
    char answer[n][40];
    for (i = 0; i < n; i++)
    {
        char temp[40] = {'\0'};
        strcpy(answer[i], convert(&op[i][0], &in[i][0], &out[i][0], temp));
    }
    for (i = 0; i < n; i++)
    {
        cout << "Case #" << i + 1 <<": " << answer[i] <<endl;
    }
    return 0;
}