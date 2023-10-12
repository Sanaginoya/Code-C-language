#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
    char a[200], b[200];
    cin.get(a, 200);
    cin.get();
    cin.get(b, 200);
    if (strcmp(a, b) == 0)
    {
        cout << "0" <<endl;
    }
    else
    {
        int i, j;
        i = j = 0;
        for(i = j = 0;;i++, j++)
        {
            if (a[i] == b[j])
            continue;
            else
            {
            cout << a[i] - b[j] <<endl;
            break;
        }
    }
}
return 0;
}