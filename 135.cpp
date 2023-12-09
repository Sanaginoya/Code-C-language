#include <iostream>
using namespace std;
int birthdayify (long long a)
{
    long long b;
    int c;
    b = a / 10000;
    c = b % 100000000;
    return c;
}
int partition (long long number[], int birthday[], int left, int right)
{
    int temp1;
    temp1 = birthday[left];
    long long temp2 = number[left];
    do
    {
        while (((left < right) && (temp1 < birthday[right])) || ((left < right) && (temp1 == birthday[right]) && (temp2 <= number[right])))
        right--;
        if ((left < right) && (temp1 >= birthday[right]))
        {
            birthday[left] = birthday[right];
            number[left] = number[right];
            left = left + 1;
        }
        while (((left < right) && (temp1 > birthday[left])) || ((left < right) && (temp1 == birthday[left]) && (temp2 > number[left])))
        left++;
        if ((left < right) && (temp1 <= birthday[left]))
        {
            birthday[right] = birthday[left];
            number[right] = number[left];
            right = right - 1;
        }
    } while (left != right);
    birthday[left] = temp1;
    number[left] = temp2;
    return left;
}
void quicksort (long long number[], int birthday[], int left, int right)
{
    int m;
    if (left >= right)
    return;
    m = partition(number, birthday, left, right);
    quicksort(number, birthday, left, m - 1);
    quicksort(number, birthday, m + 1, right);
    return;
}
int main()
{
    int n;
    cin >> n;
    long long number[n];
    int i;
    int birthday[n];
    for (i = 0; i < n; i++)
    {
        cin >> number[i];
        birthday[i] = birthdayify(number[i]);
    }
    quicksort(number, birthday, 0, n - 1);
    for (i = n - 1; i >= 0; i--)
    {
        cout << number[i] << endl;
    }
    return 0;
}