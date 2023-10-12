#include <iostream>
using namespace std;
int main()
{
    char isbn[14];
    cin >> isbn;
    int sum = 0;
    sum = (int(isbn[0]) - 48) + 2 * (int(isbn[2]) - 48) + 3 * (int(isbn[3]) - 48) + 4 * (int(isbn[4]) - 48) + 5 * (int(isbn[6]) - 48) + 6 * (int(isbn[7]) - 48) + 7 * (int(isbn[8]) - 48 ) + 8 * (int(isbn[9]) - 48) + 9 * (int(isbn[10]) - 48);
    int fin = sum % 11;
    if (fin == (int(isbn[12]) - 48))
    cout << "Right";
    else if (fin != (int(isbn[12]) - 48) && isbn[12] != 'X' && fin != 10)
    {
        isbn[12] = char(fin + 48);
        cout << isbn;
    }
    else if(fin == 10 && isbn[12] == 'X')
    {
        cout << "Right";
    }
    else if(fin == 10 && isbn[12] != 'X')
    {
        isbn[12] = 'X';
        cout << isbn;
    }
     else if (fin != (int(isbn[12]) - 48) && isbn[12] == 'X' && fin != 10)
    {
        isbn[12] = char(fin + 48);
        cout << isbn;
    }
    return 0;
}