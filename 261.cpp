#include <stdio.h>
#include <stdlib.h>

int power( int x, int y)
{
    if (y == 0)
    return 1;
    int result = x;
    for(int i = 0; i < y - 1; i++)
    result *= x;
    return result;
}
int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d", power(x, y));
    return 0;

}