#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i, j;
    long long sum = 0;
    int temp, a;
    int* number = (int*)calloc(2000000, 4);
    if (number != NULL){
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        int a1[a];
        for (j = 0; j < a; j++)
        {
            scanf("%d", &a1[j]);
            temp = a1[j] + 1000000;
            if (number[temp] < 3){
            number[temp]++;
            if (number[temp] == 1)
            sum += a1[j];
            else if (number[temp] == 2)
            sum -= a1[j];
            }
        }
    }
    cout << sum;
    }
    return 0;
}