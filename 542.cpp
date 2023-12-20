#include <stdio.h>
#include <stdlib.h>

void mySort( int *ary, int left, int right)
{
    int i, j;
    for (i = left; i < right; i++)
    {
        for (j = left; j < right - (i - left); j++)
        {
            if (ary[j] > ary[j + 1])
            {
                int temp1;
                temp1 = ary[j];
                ary[j] = ary[j + 1];
                ary[j + 1] = temp1;
            }
        }
    }
}

int main()  
{  
    int array[100], i, n;
    
    scanf("%d",&n);

    for ( i = 0; i < n; i ++ ){
        scanf("%d", &array[i]);
    }

    mySort(array, 0, n - 1);

    for ( i = 0; i < n; i ++ ){
        printf("%d ", array[i]);
    }
    printf("\n");  
    return 0;  
}  