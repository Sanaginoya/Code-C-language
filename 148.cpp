#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int a, b, c;
    int j;
    a = b = c = j = 0;
    for (a = 0; a <= 50; a++)
       for (b = 0; b <= 16; b++)
          for (c = 0; c <= 100; c++)
          {
            if (a != 0 && b != 0 && c != 0 && a != b && b != c && a != c)
            {
                if (((a > b) && (a < c)) || ((a < b) && (a > c)))
                {
                    if (a % 2 == 0)
                    {
                        if (c == 8 || c == 18 || c == 28 || c == 38 || c == 48 || c == 58 || c == 68 || c == 78 || c == 88)
                        {
                            if((b < 10 && a >= 10) || (b >= 10))
                            {
                                if (((2 * a + 6 * b + c) > 0.9 * N) && ((2 * a + 6 * b + c) <= N))
                                {
                                    cout << a << " " << b << " " << c << " " <<endl;
                                    j++;
                                }
                            }
                        }
                    }
                }
            }
          }
          if (j == 0)
          {
            cout << "no answer";
          }
          return 0;
}