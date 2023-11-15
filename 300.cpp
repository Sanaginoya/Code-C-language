#include <iostream>
using namespace std;
int main()
{
    int seat;
    cin >> seat;
    struct ticket
    {
        int ope;
        char source;
        char dest;        
    } sum[60];
    int i = 0;
    for (i = 0;; i++)
    {
        cin >> sum[i].ope;
        if (sum[i].ope != 0)
        cin >> sum[i].source >> sum[i].dest;
        else
        break;
    }
    int AB, BC, CD;
    AB = BC = CD = seat;
    for (i = 0; ; i++)
    {
        if (sum[i].ope == 0)
        break;
        else if (sum[i].ope == 1)
        {
            if (sum[i].source == 'A' && sum[i].dest == 'B')
            AB = AB - 1;
            else if (sum[i].source == 'A' && sum[i].dest == 'C')
            {
                AB = AB - 1;
                BC = BC - 1;
            }
            else if (sum[i].source == 'A' && sum[i].dest == 'D')
            {
                AB = AB - 1;
                BC = BC - 1;
                CD = CD - 1;
            }
            else if (sum[i].source == 'B' && sum[i].dest == 'C')
            {
                BC = BC - 1;
            }
            else if (sum[i].source == 'B' && sum[i].dest == 'D')
            {
                BC = BC - 1;
                CD = CD - 1;
            }
            else if (sum[i].source == 'C' && sum[i].dest == 'D')
            CD = CD - 1;
        }
        else if (sum[i].ope == 2)
        {
            if (sum[i].source == 'A' && sum[i].dest == 'B')
            AB = AB + 1;
            else if (sum[i].source == 'A' && sum[i].dest == 'C')
            {
                AB = AB + 1;
                BC = BC + 1;
            }
            else if (sum[i].source == 'A' && sum[i].dest == 'D')
            {
                AB = AB + 1;
                BC = BC + 1;
                CD = CD + 1;
            }
            else if (sum[i].source == 'B' && sum[i].dest == 'C')
            {
                BC = BC + 1;
            }
            else if (sum[i].source == 'B' && sum[i].dest == 'D')
            {
                BC = BC + 1;
                CD = CD + 1;
            }
            else if (sum[i].source == 'C' && sum[i].dest == 'D')
            CD = CD + 1;
        }
    }
    int answer = (AB < BC) ? AB : BC;
    answer = (answer < CD) ? answer : CD;
    cout << answer;
    return 0;
}