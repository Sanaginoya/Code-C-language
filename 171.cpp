#include <iostream>
using namespace std;
int main ()
{
    long long a, b;
    char s;
    cin >> a >> b >> s;
    switch (s)
    {
    case '+' :
    cout << a + b <<endl;
    break;
    case '-' :
    cout << a - b <<endl;
    break;
    case '*' :
    cout << a * b <<endl;
    break;
    case '/' :
    if (b!=0)
    {   cout << a / b <<endl;
        break;
    }
    else
    {   cout << "NO" <<endl;
        break;
    }
    case '%' :
    if (b!=0)
    {   cout << a % b <<endl;
        break;
    }
    else
    {   cout << "NO" <<endl;
        break;
    }
    }
    return 0;
}