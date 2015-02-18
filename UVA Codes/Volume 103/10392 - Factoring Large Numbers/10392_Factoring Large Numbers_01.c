#include <stdio.h>

#define SIZE 1000000

char prime[2 + (SIZE >> 4)];

#define isprime(i) !(prime[i>>4] & ( 1 << ((i & 15)>>1) ))

void sieve(void)
{
    prime[0] = 0b10010001;

    int i, j, l, m;
    l = (int)sqrt(SIZE) >> 1;
    m = SIZE >> 1;
    for(i = 1; i < l; ++i)
        if(!(prime[i >> 3] & (1 << (i & 7))))
            for(j = 2 * i * (i + 1); j < m; j += i + i + 1)
                prime[j >> 3] |= 1 << (j & 7);
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("10392_Factoring Large Numbers_01.inp", "r", stdin);
#endif

    sieve();

    long long n, l, i;
    while(scanf("%lld", &n) != EOF && n >= 0)
    {
        while(!(n & 1))
        {
            printf("%4c2\n", ' ');
            n >>= 1;
        }

        for(i = 3; i * i <= n && i<SIZE; i += 2)
            if(isprime(i))
            {
                while(!(n % i))
                {
                    printf("%4c%lld\n", ' ', i);
                    n /= i;
                }
            }

        if(n > 1)
            printf("%4c%lld\n", ' ', n);
        putchar('\n');
    }

    return 0;
}
