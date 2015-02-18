#include <stdio.h>

int main()
{
    int n,i;
    long long a,b,c,d;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a>b) d=a, a=b, b=d;
        if(a>c) d=a, a=c, c=d;
        if(b>c) d=b, b=c, c=d;
        printf("Case %d: %lld\n",i,b);
    }
    return 0;
}
