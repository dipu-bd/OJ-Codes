#include <stdio.h>
#include <stdlib.h>

#define SIZE 500000

int swap;
int item[SIZE];

void mergesort(int left, int right)
{

}

int main()
{
    int n, i;
    while(scanf("%d", &n)!=EOF && n>0)
    {
        for(i=0;i<n;++i)
            scanf("%d", item + i);

        swap = 0;
        quicksort(0, n);

        printf("%d\n", swap);
    }

    return 0;
}
