#include <stdio.h>
#include <string.h>

void f(char s[], int l, int r)
{
    char temp;
    if (l >= r)
    return;
    else
    {
        temp = s[l];
        s[l] = s[r];
        s[r] = temp;
    }
    f(s,l+1,r-1);
}

int main(){
    char s[10001];
    scanf("%s", s);    //指针是不用取地址的
    f(s,0,strlen(s)-1);
    printf("%s",s);
}

