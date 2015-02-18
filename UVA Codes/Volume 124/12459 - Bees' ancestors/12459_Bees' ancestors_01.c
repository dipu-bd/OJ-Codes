#include <stdio.h>

int max;
long long fib[85];

int main()
{
    max = 2;
    fib[0] =  fib[1] = 1;

    int n;
    while(scanf("%d", &n) != EOF && n > 0)
    {
        for(; n >= max; ++max)
            fib[max] = fib[max - 1] + fib[max - 2];

        printf("%lld\n", fib[n]);
    }

    return 0;
}
