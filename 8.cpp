#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    if (a >= 90)
    cout << "4.0" <<endl;
     else if (a < 90 && a >= 86)
    cout << "3.7" <<endl;
     else if (a < 86 && a >=83)
    cout << "3.3" <<endl;
     else if (a < 83 && a >= 80)
    cout << "3.0" <<endl;
     else if (a <80 && a >=76)
    cout << "2.7" <<endl;
     else if (a <76 && a >= 73)
    cout << "2.3" <<endl;
     else if (a < 73 && a >= 70)
    cout << "2.0" <<endl;
     else if (a < 70 && a >= 66)
    cout << "1.7" <<endl;
     else if (a < 66 && a >= 63)
    cout << "1.3" <<endl;
     else if (a < 63 && a >= 60)
    cout << "1.0" <<endl;
     else if (a < 60)
    cout << "0" <<endl;
    return 0;
}