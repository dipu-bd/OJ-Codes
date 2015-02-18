#include <stdio.h>
#include <math.h>

#define LIMIT 50000000

int main()
{
    freopen("138_Street Numbers_02.out","w", stdout);

    double p;
    long long int m,n,d;

    for(n=2; n<LIMIT; ++n)
    {
        p = 0.5 * (-1 + sqrt(1 + 8*n*n));
        d = (long long int)p;
        if(d>n && p==d) printf("%10lld%10lld\\n",n, d);
    }


    return 0;
}
