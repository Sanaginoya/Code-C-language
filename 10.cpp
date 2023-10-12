#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int C;
    cin >> C;
    cout << fixed << setprecision(2) << ((double)C - 32.0) * 5.0 / 9.0;
    return 0;
}