#include <stdio.h>

int main()
{
    int n;
    long long a,b;
    register int i;
    register long long c;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&a,&b);
        c=(a/3)*(b/3);
        if(c<=0) c=1;
        printf("%lld\n",c);
    }
    return 0;
}
