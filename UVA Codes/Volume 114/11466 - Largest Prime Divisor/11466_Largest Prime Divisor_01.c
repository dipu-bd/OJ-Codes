#include <stdio.h>
#include <math.h>

#define SIZE 10000000
char prime[2 + (SIZE >> 4)];

#define GET(i) (prime[(i)>>3] & ( 1 << ((i)&7) ))
#define isprime(i) ((i)==2 || ((i)&1 && !GET((i)>>1)))

void sieve(void)
{
    prime[0] = 0b10010001;

    int i, j, l, m;
    l = (int)sqrt(SIZE) >> 1;
    m = SIZE >> 1;
    for(i = 1; i < l; ++i)
        if(!GET(i))
            for(j = 2 * i * (i + 1); j < m; j += i + i + 1)
                prime[j >> 3] |= 1 << (j & 7);
    return;
}

long long largestDivisor(long long n)
{
    if(n < SIZE && isprime(n)) return -1;

    int c = 0;
    long long i, j, s, l, m;
    s = (long long)sqrt(n);

    /* if divisible by 2 */
    l = -1;
    if(!(n & 1))
    {
        l = 2;
        do
            n >>= 1;
        while(n && !(n & 1));
        ++c;
    }

    /* check other factors */
    for(i = 3; i <= s; i += 2)
        if(isprime(i))
        {
            m = n / i;
            if(n == m * i)
            {
                l = i;
                do
                {
                    n = m;
                    m = n / i;
                }
                while(n == m * i);
                ++c;
            }
        }

    if(n >= i) l = n, ++c;

    return (c < 2) ? -1 : l;
}

int main()
{
#ifndef ONLINE_JUDGE
     freopen("11466_Largest Prime Divisor_01.inp","r",stdin);
#endif
    sieve();

    long long n, m;
    while(scanf("%lld", &n) != EOF && n)
    {
        n = (n < 0) ? -n : n;
        printf("%lld\n", largestDivisor(n));
    }

    return 0;
}

