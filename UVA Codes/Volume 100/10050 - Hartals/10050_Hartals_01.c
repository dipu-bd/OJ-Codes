#include <stdio.h>

int main()
{
    int tc,n,p,h;
    int arry[3660];
    register int i,j,t,sum;
    for(scanf("%d",&tc); tc>0; tc--)
    {
        scanf("%d",&n);
        scanf("%d",&p);
        for(sum=0,j=0; j<n; j++)
            arry[j]=0;
        for(i=0; i<p; i++)
        {
            scanf("%d",&h);
            for(j=1,t=j*h-1; t<n; j++,t=j*h-1)
                if(t%7<5) arry[t]=1;
        }

        for(sum=0,j=0; j<n; j++)
            if(arry[j]) sum++;
        printf("%d\n",sum);
    }
    return 0;
}
