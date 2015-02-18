#include <stdio.h>

#define ULL unsigned long long int

int main()
{
    ULL n,b;
    while(scanf("%llu",&n)==1 && n)
    {
        b = (10*n)/9;
        if(n%9) printf("%llu\n",b);
        else printf("%llu %llu\n",b-1,b);
    }
    return 0;
}
