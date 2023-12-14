/* #include <stdio.h>

int josephus(int n, int k) {
    if (n == 1)
        return 1;                       //相当于倒着进行数学归纳法。
    else
        return (josephus(n - 1, k) + k - 1) % n + 1;    //一种取余后还能取到n的优化方法。
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", josephus(n, k));
    return 0;
} */
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int i, answer = 1;
    if (n > 1){
    for (i = 2; i <= n; i++)
    {
        answer = (answer + m - 1) % i + 1;
    }
    }
    cout << answer;
    return 0;
}
