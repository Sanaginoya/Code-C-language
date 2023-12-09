#include <iostream>
#include <stdio.h>
using namespace std;
int step = 0;
void move (int n, char a1, char a2, char a3)
{
    if (n == 1)
    {   
        step++;
        printf("[step %d]  move plate 1#  from %c to %c\n", step, a1, a3);
        return;
    }
    else
    {
        move (n - 1, a1, a3, a2);
        step++;
        printf ("[step %d]  move plate %d#  from %c to %c\n", step, n, a1, a3);
        move (n - 1, a2, a1, a3);
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    move (n, 'a', 'b', 'c');
    cout << step;
    return 0;
}