#include <stdio.h>

int main()
{
    int tc, st, x;
    scanf("%d",&tc);
    register i, max;
    for(i=1;i<=tc;i++)
    {
        scanf("%d",&st);
        for(max=0; st>0 && scanf(" %d",&x)==1; st--)
            if(max<x) max=x;
        printf("Case %d: %d\n",i,max);
    }
    return 0;
}
