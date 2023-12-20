#include <stdio.h>

void word(char *s){
    int letter[26] = {0};
    char a = 'a';
    char* temp = s;
    for (int i = 0; i < 26; i++){
    while(*temp)
    {
        if (*temp == (char)(a + i))
        letter[i]++;
        temp++;
    }
    temp = s;
    }
    int maxn = letter[0], minn = 150;
    for (int i = 1; i < 26; i++)
    {
        if(maxn < letter[i])
        maxn = letter[i];
        if ((minn > letter[i]) && (letter[i] > 0))
        minn = letter[i];
    }
    int result = maxn - minn;
    int flag = 0;
    if ((result == 0) || (result == 1))
    {
        printf ("No Answer\n");
        printf ("0");
    }
    if (result > 1)
    {
        for (int i = 1; i <= result; i++)
        {
            if (result % i == 0)
            flag++;
        }
        if (flag == 2)
        {
            printf ("Lucky Word\n");
            printf ("%d", (maxn - minn));
        }
        else
        {
            printf ("No Answer\n");
            printf ("0");
        }
    }
}
int main(void){
    char s[102];
    scanf("%s",s);
    word(s);
    return 0;
}
