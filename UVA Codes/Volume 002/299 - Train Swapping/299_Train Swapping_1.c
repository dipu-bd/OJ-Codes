#include <stdio.h>
#include <stdlib.h>

int *inp;
int swap(int *);

int main()
{
    inp = calloc(60,sizeof(int));
    int tc, lc;
    scanf("%d",&tc);
    register i;
    for(;tc>0;tc--)
    {
        scanf("%d",&lc);
        for(i=0;i<lc;i++)
            scanf("%d",&inp[i]);
        printf("Optimal train swapping takes %d swaps.\n", swap(&lc));
    }
    return 0;
}

int swap(int *lc)
{
    register i,j,s,t;
    for(i=0,s=0;i<*lc;i++)
    {
        t = inp[i];
        for(j=i+1;j<*lc && t>inp[j];j++)
            inp[j-1]=inp[j], s++;
        inp[j-1] = t;

        t = inp[i];
        for(j=i-1;j>=0 && t<inp[j];j--)
            inp[j+1]=inp[j], s++;
        inp[j+1] = t;
    }

    return s;
}
