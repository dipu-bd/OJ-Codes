#include <stdio.h>

int main()
{
    long long int n,r;
    while(scanf("%lld",&n)==1)
    {
        if(n<0) break;
        r = 1+(n*(n+1))/2;
        printf("%lld\n",r);
    }
    return 0;
}
