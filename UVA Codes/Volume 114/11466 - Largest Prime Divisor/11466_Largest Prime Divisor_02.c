#include <stdio.h>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("11466_Largest Prime Divisor_01.inp", "r", stdin);
#endif

    long long n, l, i;
    int c;

    while(scanf("%lld", &n) != EOF && n)
    {
        if (n < 0) n = -n;

        c = 0;
        if(!(n & 1))
        {
            l = 2;
            do
                n >>= 1;
            while(!(n & 1));
            ++c;
        }

        for(i = 3; i * i <= n; i += 2)
        {
            if(!(n % i))
            {
                l = i;
                do
                    n /= i;
                while(!(n % i));
                ++c;
            }
        }

        if(n > 1 && c)
            printf("%lld\n", n);
        else if(c < 2)
            puts("-1");
        else printf("%lld\n", l);
    }

    return 0;
}
