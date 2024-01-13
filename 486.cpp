#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
char standard[5];
int cmp (const void* a1, const void* a2)
{
    char* in1 = *((char**)a1);                                    //易错，需要用二重指针。
    char* in2 = *((char**)a2);
    int i, j;
    int flag1, flag2;
    int length = strlen(in1);
    for (i = 0; i < length; i++)
    {
        for(flag1 = 0; flag1 < 4; flag1++)
        {
            if (standard[flag1] == *(in1 + i))
            break;
        }
        for(flag2 = 0; flag2 < 4; flag2++)
        {
            if (standard[flag2] == *(in2 + i))
            break;
        }
        if (flag1 == flag2)
        continue;
        else if (flag1 > flag2)
        return 1;
        else
        return -1;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    char* in[n];
    int i;
    cin >> standard;
    for (i = 0; i < n; i++)
    {
        in[i] = (char *)malloc(30);                     //浮点只能和浮点比较
        if (in[i] == NULL)
        return 0;
        cin >> in[i];
    }
    qsort(in, n, sizeof(char*), cmp);                          //超级坑！！yoj看上去没有64位的算力。
    for (i = 0; i < n; i++)
    cout << in[i] << endl;
    for (i = 0; i < n; i++)
    free(in[i]);
    return 0;
}