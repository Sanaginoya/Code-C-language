#include <iostream>
using namespace std;
int main ()
{
    int a, b, c, d, e;
    int sum;
    a = b = c = d = e = sum = 0;
    cin >> sum;
    for(e = 1; e <= 5; e++)
    {
        for(d = 1; d <= 5; d++)
        {
    for(c = 1; c <= 5; c++)
    {
    for(b = 1; b <= 5; b++)
    {
    for(a = 1; a <= 5; a++)
    { 
        if (a != b && a !=c && a != d && a != e && b != c && b != d && b != e && c != d && c != e && d != e && (a + 4 * b + 6 * c + 4 * d + e == sum))
        {
            cout << e << " " << d << " " << c << " " << b << " " << a <<endl;
            goto exit;
        }
    }
    }
    }
        }
    }
    exit :
    return 0;
}