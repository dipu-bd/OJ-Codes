#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10000

int max=0;
int array[LIMIT];

void printMedian()
{
    int i = max>>1;
    if(1&max)
        printf("%d\n", array[i]);
    else
        printf("%d\n",(array[i]+array[i-1])>>1);
}

int main()
{
    int i,p,q,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<max && n>array[i]; ++i);
        for(p=n; i<=max; ++i, p=q)
        {
            q = array[i];
            array[i] = p;
        }

        ++max;
        printMedian();
    }

    return 0;
}

