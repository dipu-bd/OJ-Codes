#include <stdio.h>

int main()
{
    int t, cas;
    long long x;

    scanf("%d", &t);
    for(cas = 1; cas <= t; ++cas)
    {
        scanf("%lld", &x);
        printf("Case %d: ", cas);
        if(x % 9 == 0)
            printf("%lld %lld\n", 10 * (x / 9) - 1, 10 * (x / 9));
        else
            printf("%lld\n", 10 * (x / 9) + (x % 9));
    }

    return 0;
}
