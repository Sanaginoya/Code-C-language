#include <iostream>
#include <cmath>
using namespace std;
int distance (double x, double y, double z, double a[], double b[], double c[], double d[])
{
    int i = 0;
    int sum = 0;
    sum = floor(sqrt(pow((x - a[0]), 2) + pow((y - a[1]), 2) + pow((z - a[2]), 2))) + floor(sqrt(pow((x - b[0]), 2) + pow((y - b[1]), 2) + pow((z - b[2]), 2))) + floor(sqrt(pow((x - c[0]), 2) + pow((y - c[1]), 2) + pow((z - c[2]), 2))) + floor(sqrt(pow((x - d[0]), 2) + pow((y - d[1]), 2) + pow((z - d[2]), 2)));
    return sum;
}
int main()
{
    double a[3], b[3], c[3], d[3];
    int i = 0, j ,k;
    for (i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < 3; i++)
    {
        cin >> b[i];
    }
    for (i = 0; i < 3; i++)
    {
        cin >> c[i];
    }
    for (i = 0; i < 3; i++)
    {
        cin >> d[i];
    }
    double min[3], max[3];
    int Min;
    for (i = 0; i < 3; i++)
    {
        min[i] = (a[i] > b[i]) ? b[i] : a[i];
        min[i] = (min[i] > c[i]) ? c[i] : min[i];
        min[i] = (min[i] > d[i]) ? d[i] : min[i];
    }
    for (i = 0; i < 3; i++)
    {
        max[i] = (a[i] > b[i]) ? a[i] : b[i];
        max[i] = (max[i] > c[i]) ? max[i] : c[i];
        max[i] = (max[i] > d[i]) ? max[i] : d[i];
    }
    Min = distance(min[0], min[1], min[2], a,b,c,d);
    int flag = 0;
    int x[10000], y[10000], z[10000];               //数组尽量往大开。
    for (i = min[0]; i < max[0]; i++)
    for (j = min[1]; j < max[1]; j++)
    for (k = min[2]; k < max[2]; k++)
    {
        if (Min > distance(i,j,k,a,b,c,d))
        {
            Min = distance(i,j,k,a,b,c,d);
            flag = 0;
            x[flag] = i;
            y[flag] = j;
            z[flag] = k;
            flag++;
        }
        else if (Min == distance(i,j,k,a,b,c,d))
        {
            x[flag] = i;
            y[flag] = j;
            z[flag] = k;
            flag++;
        }
    }
    cout << Min << " " << flag <<endl;
    for (i = 0; i < flag; i++)
    cout << x[i] << " " << y[i] << " " << z[i] <<endl;
    return 0;
}