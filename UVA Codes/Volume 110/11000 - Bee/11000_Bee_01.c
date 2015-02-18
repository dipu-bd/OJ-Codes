#include <stdio.h>

int max;
long long fib[80];

int main()
{
    /*config*/
    max = 2;
    fib[0] = 1;
    fib[1] = 2;

    /*process*/
    int n, m;
    while(scanf("%d", &n) != EOF && n >= 0)
    {
        m = n + 1;
        for(; m >= max; ++max)
            fib[max] = fib[max - 1] + fib[max - 2];

        printf("%lld %lld\n", fib[n] - 1, fib[m] - 1);
    }

    return 0;
}
