#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10000001
int len = 0;
bool prime[MAX + 10];
int primes[1000000];

void sieve()
{
    for(int i = 4; i < MAX; i += 2)
        prime[i] = true;

    int i, m = sqrt(MAX);
    for(i = 3; i <= m; i += 2)
    {
        if(!prime[i])
        {
            primes[len++] = i;
            for(int j = i * i; j < MAX; j += i)
                prime[j] = true;
        }
    }

    for(; i < MAX; i += 2)
        if(!prime[i]) primes[len++] = i;
}

int divcount(long long n)
{
    if(n < 2) return 0;

    int res = 1;

    while(!(n & 1)) n >>= 1;

    for(int i = 0; i < len && n > 1; ++i)
    {
        const int& p = primes[i];
        if(!(n % p))
        {
            int c = 0;
            do
            {
                n /= p;
                ++c;
            }
            while(!(n % p));
            res *= c + 1;
        }
    }

    if(n > 1) res <<= 1;
    return res - 1;
}

int main()
{
    sieve();

    long long n;
    int r, test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%lld", &n);
        r = divcount(n);
        printf("Case %d: %d\n", cas++, r);
    }

    return 0;
}

