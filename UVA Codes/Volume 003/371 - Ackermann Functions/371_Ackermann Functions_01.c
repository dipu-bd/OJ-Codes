#include <stdio.h>

int main()
{
    long long int a,b, lc, mx, k,c,n;
    while(scanf("%lld %lld",&a,&b)!=EOF && a>0)
    {
        lc = mx = 0;
        if(a>b) c=a, a=b, b=c;

        for(k=a; k<=b; ++k)
        {
            n=k, c=0;
            do
                n = (1&n) ? 3*n+1 : n>>1, ++c;
            while (n>1);

            if (c>lc) lc=c, mx=k;
        }

        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",a,b,mx,lc);
    }

    return 0;
}
