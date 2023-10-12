#include <stdio.h>
#include <math.h>
int main()
{
    double x;
    int i;
    scanf ("%lf", &x);
    for (i = 1; i <= 2; i++)
    if (fabs(x) <= 1.0)
    {
        x = fabs(x - 1) - 2;
    }
    else
    {
        x = 1 / (1 + pow(x,2.0));
    }
    printf ("%.2f", x);
    return 0;
}