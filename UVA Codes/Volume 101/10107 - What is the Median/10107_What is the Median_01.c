#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10000

int max=0;
int array[LIMIT];

int main()
{
    int n;
    while(scanf("%d",&n)==1)
        max++, addNum(n), printMedian();


    for(n=0;n<max;++n)
        printf("%d ", array[n]);

    return 0;
}

int comp(const int *a, const int *b)
{
    return (*a) - (*b);
}

void addNum(int n)
{
    array[max-1] = n;
    qsort(array,max,sizeof(int),comp); */
}

void printMedian()
{
    int n = max>>1;
    if(1&max)
        printf("%d\n", array[n]);
    else
        printf("%d\n",(array[n]+array[n-1])>>1);
}

