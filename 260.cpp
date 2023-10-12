#include <iostream>
using namespace std;
int main()
{
    int n;
    int m;
    cin >> n >> m;
    int a[n];
    int result = 0;
    int sum = 0;
    int i = 0, j = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int temp = 0, flag = 0;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag++;
            }
        }
        if (flag == 0)
        break;
    }
    int left = 0, righ = n - 1;
    int mid = (left + righ) / 2;
    while (left <= righ)
    {
        if (a[mid] == m)
        {
            result = mid + 1;  //易错点 ：mid的值可能为0，因此用mid检测并不靠谱，改进就是这里就加一个参量，并在输出时减去即可。
            sum++;
            break;
        }
        else if (a[mid] < m)
        {
            left = mid + 1;
            sum++;
        }
        else
        {
            righ = mid - 1;
            sum++;
        }
        mid = (left + righ) / 2;
    }
    if (result == 0)
    cout << "-1" <<endl;
    else
    cout << result - 1 <<endl;
    cout << sum;
    return 0;
}