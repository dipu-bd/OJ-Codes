#include <stdio.h>
#include <math.h>

#define NO printf("No\n")
#define YES printf("Yes\n")

long long pow2 (long long p)
{
    if (p < 1) return 1;
    return 2 * pow2 (p - 1);
}

int isprime (long long p)
{
    if (p < 2) return 0;
    if (p == 2) return 1;
    if (!(p & 1)) return 0;

    long long i, m;
    m = (long long)sqrt(p) ;
    for (i = 3; i <= m; i += 2)
        if (p == (p / i) * i) return 0;

    return 1;
}

int isperfect (long long p)
{
    long long i, n, sum, d;
    n = pow2(p);
    n = (n * (n - 1) ) >> 1;
    for (sum = 1, i = 2, d = n; d >= i; i++)
    {
        d = n / i;
        if (d >= i && n == d * i)
            sum += d + i;
    }

    return (sum == n);
}


int main()
{
    int n;
    long long p;
    scanf ("%d", &n);

    while (n--)
    {
        scanf ("%lld,", &p);
        if (isprime (p) && isperfect (p) ) YES;
        else NO;
    }
    return 0;
}

