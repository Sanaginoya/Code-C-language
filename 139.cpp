#include <iostream>
#include <cmath>
using namespace std;
int my_max (int arr1[], int sz1)
{
    int temp;
    temp = arr1[0];
    for(int p1 = 0; p1 < sz1 - 1; p1++)
    {
        if(temp < arr1[p1 + 1])
        temp = arr1[p1 + 1];
    }
    return temp;
}
int my_avg (int arr2[], int sz2)
{
    int temp2 = 0;
    for (int p2 = 0; p2 <sz2; p2++)
    temp2 += arr2[p2];
    temp2 = round(temp2 / (double)sz2);
    return temp2;
}
int my_min (int arr3[], int sz3)
{
    int temp3;
    temp3 = arr3[0];
    for(int p3 = 0; p3 < sz3 - 1; p3++)
    {
        if(temp3 > arr3[p3 + 1])
        temp3 = arr3[p3 + 1];
    }
    return temp3;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max, avg, min;
    max = my_max(a,n);
    avg = my_avg(a,n);
    min = my_min(a,n);
    cout << max << " " << min << " " << avg <<endl;
    return 0;

}