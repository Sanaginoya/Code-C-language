#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    struct w
    {
        char zimu;
        int times;
    } word[26];
    char input[300];
    cin.getline(input, 300);
    int i = 0;
    int j = 0;
    for (i = 0; i < 26; i++)
    {
        word[i].zimu = 'a' + i;
        word[i].times = 0;
    }
    for (i = 0; i < strlen(input); i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (*(input + i) == word[j].zimu || *(input + i) == (char)((int)(word[j].zimu) - 32))
            {
                word[j].times++;
                break;
            }
        }
    }
    int temp1;
    char temp2;
    for (i = 0; i < 25; i++)
    {
        for (j = 0; j < 25 - i; j++)
        {
            if (word[j].times < word[j + 1].times)
            {
                temp1 = word[j].times;
                word[j].times = word[j + 1].times;
                word[j + 1].times = temp1;
                temp2 = word[j].zimu;
                word[j].zimu = word[j + 1].zimu;
                word[j + 1].zimu = temp2;
            }
            if (word[j].times == word[j + 1].times)
            {
                if ((int)word[j].zimu > (int)word[j + 1].zimu)
                {
                    temp2 = word[j].zimu;
                    word[j].zimu = word[j + 1].zimu;
                    word[j + 1].zimu = temp2;
                }
            }
        }
    }
    for (i = 0; i < 26; i++)
    {
        if (word[i].times != 0)
        {
            cout << word[i].zimu << " " << word[i].times <<endl;
        }
        else
        break;
    }
    return 0;
}