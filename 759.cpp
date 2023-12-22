#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 2100
// to be finished
#include <iostream>
#include <cstring>
using namespace std;
int readData (char* s1, char* s2)
{
    cin.getline(s1, 2100);
    cin.getline(s2, 2100);
    int K;
    cin >> K;
    return K;
}
int fuzzySubstr (char s1[], char s2[], int K, int* unmatched)
{
    char* test = strstr(s2, s1);
    if (test == NULL){
    int i, j;
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    int unmatch = 0;
    *unmatched = 2000;
    int flag = 0, flagtemp = 0;
    for (i = 0; i < length2; i++)
    {
        flagtemp = i;
        for (j = 0; j < length1; j++)
        {
            if (s1[j] != s2[i + j])
            {
                unmatch++;
            }
            if (unmatch > K)
            {
                unmatch = 0;
                break;
            }
        }
        if (((*unmatched) > unmatch) && (unmatch != 0))
        {
            *unmatched = unmatch;
            flag = flagtemp;
        }
        unmatch = 0;
    }
    if ((*unmatched) == 2000)
    return -1;
    else
    {
        return flag;
    }
    }
    else
    {
        *unmatched = 0;
        return (test - s2);
    }
}

int main()
{
    char s1[SIZE], s2[SIZE], s[SIZE];
    int K;
    int matchBegin;
    int unmatched;
    K = readData(s1, s2);
    matchBegin = fuzzySubstr(s1, s2, K, &unmatched);

    if ( matchBegin == -1 )
        printf("-1\n");
    else{
        printf("%d %d\n", unmatched, matchBegin);
        strncpy(s, s2 + matchBegin, strlen(s1) );
        s[strlen(s1)] = '\0';
        printf("%s\n", s);
    }

    return 0;

}