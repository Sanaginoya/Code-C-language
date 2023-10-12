#include <iostream>
using namespace std;
int main ()
{
    int sum, n, i, j;
    char answer = 'A';
    char t;
    cin >> n;
    sum = j = 0;
    for (i = 0; i <= 7; i++)
    {
        answer = answer + i;
        if (answer == 'H' || answer == 'F')
        sum += 2;
        if (answer == 'B')
        sum += 1;
        if (answer == 'G')
        sum += 1;
        if (answer != 'B')
        sum += 1;
        if (answer != 'H' && answer != 'F')
        sum += 2;
        if (answer != 'C')
        sum += 1;
        if (sum == n)
        {
            t = answer;
            j++;
    }
        sum = 0;
        answer = 'A';
    }
    if (j == 1)
    {
        cout << t;
    }
    else
    {
        cout << "DONTKNOW";
    }
    return 0;
}