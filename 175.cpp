#include <iostream>
using namespace std;
int main()
{
    char start = 'A';
    int n, m;
    int i1 = 0;
    int j1;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {   
        if (i == 0)
        {
            for (int j = 0; j < m; j++)
            cout << (char)(start + j) ;
            cout <<endl;
        }
        else
        {
            start = start + i;
            for (i1 = 0; i1 <= (i<(m-1)?i:(m-1)); i1++)
            cout << (char)(start - i1);
            start = start - i;
            for (j1 = 1; j1 <= m - i - 1; j1++)
            cout << (char)(start + j1); 
            cout <<endl;
            start = 'A';
        }
       
    }
    return 0;
}