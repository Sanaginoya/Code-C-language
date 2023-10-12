#include <iostream>
using namespace std;
int main()
{
    int i = 1;
    int c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    int arr[] = {120, 40, 85, 50, 100, 140, 70, 100};
    int a, b, c, d;
    for (a = 1; a <= 8; a++)
       for (b = 1; b <= 8; b++)
          for (c = 1; c <= 8; c++)
             for (d = 1; d <= 8; d++)
             {
                if(a != b && a != c && a != d && b != c && b != d && c != d && c1 <= arr[a - 1] && c2 <= arr[b - 1] && c3 <= arr[c - 1] && c4 <= arr[d - 1])
                {
                    cout << a << " " << b << " " << c << " " << d <<endl;
                    i++;
             }
             }
             if (i == 1)
             cout << "-1";
             return 0;
}