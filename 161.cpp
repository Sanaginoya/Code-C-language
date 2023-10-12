#include <iostream>
using namespace std;
int main ()
{
    int o;
    cin >> o;
    int s;
    int a[4];
    a[0] = o % 10;
    a[1] = (o/10)%10;
    a[2] = (o/100)%10;
    a[3] = o/1000;
    for (int i = 0; i<4;i++)
    {
        a[i]=(a[i]+5)%10;
    }
    s=a[0]*1000+a[2]*10+a[1]*100+a[3];
    cout << s;
    return 0;
}