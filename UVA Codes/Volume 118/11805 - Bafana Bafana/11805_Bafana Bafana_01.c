#include <stdio.h>

int main()
{
    int t,n,k,p;
    scanf("%d",&t);

    register i,r;
    for(i=1;i<=t;i++)
    {
        scanf("%d %d %d",&n,&k,&p);
        r = (k+p)%n;
        if(r==0) r=n;
        printf("Case %d: %d\n",i,r);
    }
    return 0;
}
