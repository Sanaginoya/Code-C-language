#include <iostream>
using namespace std;
int main()
{
    int start = 6;
    int n;
    cin >> n;
    switch ((start + n - 1) % 7 + 1)
    {
        case 1:
        cout << "MON";
        break;
        case 2:
        cout << "TUE";
        break;
        case 3:
        cout << "WED";
        break;
        case 4:
        cout << "THU";
        break;
        case 5:
        cout << "FRI";
        break;
        case 6:
        cout << "SAT";
        break;
        case 7:
        cout << "SUN";
        break;
        default:
        break;
    }
}