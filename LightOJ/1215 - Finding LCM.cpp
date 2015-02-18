#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <iostream>

typedef long long ll;

#define SIZ 1100
int sz = 0;
int prime[SIZ];
bool flag[SIZ];

void sieve()
{
    int i, j, m;
    prime[sz++] = 2;
    for(i = 4; i < SIZ; i += 2) flag[i] = true;
    for(i = 3, m = sqrt(SIZ); i <= m; i += 2)
    {
        if(!flag[i])
        {
            prime[sz++] = i;
            for(j = i * i; j < SIZ; j += i) flag[j] = true;
        }
    }

    for( ; i < SIZ; i += 2 )
        if(!flag[i]) prime[sz++] = i;
}

int main()
{
    sieve();
    int test, cas = 1;

    ll a, b, L, l, c, t, p1, p2;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%lld %lld %lld", &a, &b, &L);

        c = 1, t = L;
        l = ((a * b) / std::__gcd(a, b));

        printf("Case %d: ", cas++);
        if(L % l)
        {
            printf("impossible\n");
            continue;
        }

        for(int i = 0; l > 1 && i < sz; ++i)
        {
            int& p = prime[i];
            if(!(l % p))
            {
                p1 = p2 = p;
                while(!(l % p2)) p2 *= p;
                while(!(t % p1)) p1 *= p;

                p1 /= p, p2 /= p;
                t /= p1, l /= p2;
                if(p1 != p2) c *= p1;
            }
        }

        if(l > 1)
        {
            p1 = l;
            while(!(t % p1)) p1 *= l;
            p1 /= l, t /= p1;
            if(p1 != l) c *= p1;
        }

        c *= t;
        if (L % c) printf("impossible\n");
        else printf("%lld\n", c);
    }

    return 0;
}

