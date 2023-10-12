#include <iostream>
using namespace std;
int main()
{
    int d1, d2;
    cin >> d1 >> d2;
    char a[8][10] = {{"Monday"},{"Tuesday"},{"Wednesday"},{"Thursday"},{"Friday"},{"Saturday"},{"Sunday"},{"Monday"}};
    cout << a[d1] << endl;
    if (d2 == 1)
    cout << "Sunday" <<endl;
    else
    cout << a[d2 - 2] <<endl;
    return 0;
}