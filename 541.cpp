#include<stdio.h>
#include<string.h>
#include <cstring>
using namespace std;

char parseCmd (char* cmdStr, char str1[], char str2[])
{
    char cmd = *cmdStr;
    if (cmd == 'C' || cmd == 'D')
    strcpy(str1, cmdStr + 2);
    else if (cmd == 'I' || cmd == 'R')
    {
        char* temp = cmdStr + 2;
        while (*temp != ' ')
        temp++;
        *temp = '\0';
        strcpy (str1, cmdStr + 2);
        strcpy (str2, temp + 1);
    }
    return cmd;
}

int countStr (char* s, char* str1)
{
    int sum = 0;
    char* flag = strstr(s, str1);
    while (1){
    if (flag != NULL)
    {
        sum += 1;
        if (*(flag + strlen(str1)) != '\0')
        flag = strstr(flag + strlen(str1), str1);
        else
        break;
    }
    else
    break;
    }
    return sum;
}

void deleteStr (char* s, char* str1)
{
    char* flag = strstr(s, str1);
    if (flag == NULL)
    return;
    else
    {
        char temp[500];
        strcpy(temp, flag + strlen(str1));
        strcpy(flag, temp);
        return;
    }
}

void insertStr(char* s, char* str1, char* str2)
{
    char* flag = strstr(s, str1);
    char* temp = NULL;
    while (1){
    if (flag != NULL)
    {
        temp = flag;
        if (*(flag + strlen(str1)) != '\0')
        flag = strstr(flag + strlen(str1), str1);
        else
        break;
    }
    else
    break;
    }
    if (temp == NULL)
    return;
    else
    {
        strcat(str2, temp);
        strcpy(temp, str2);
        return;
    }
}

char* replaceStr(char* s, char* str1, char* str2)
{
    char* flag = strstr(s, str1);
    while (1){
    if (flag != NULL)
    {
        char temp1[500], temp2[500];
        strcpy(temp1, flag + strlen(str1));
        strcpy(temp2, str2);
        strcat(temp2, temp1);
        strcpy(flag, temp2);
        if (*(flag + strlen(str2)) != '\0')
        flag = strstr(flag + strlen(str2), str1);
        else
        break;
    }
    else
    break;
    }
    return s;
}

int main()
{
	char s[500], cmdStr[500], str1[500], str2[500], cmd;

    gets(s);
	gets(cmdStr);

    cmd = parseCmd(cmdStr, str1, str2);

    switch ( cmd )
    {
    case 'C':
        printf("%d\n", countStr(s, str1));
        break;
    case 'D':
        deleteStr(s, str1);
        printf("%s\n", s);
        break;
    case 'I':
        insertStr(s, str1, str2);
        printf("%s\n", s);
        break;
    case 'R':
        printf("%s\n", replaceStr(s, str1, str2));
        break;
    }
    return 0;
}
