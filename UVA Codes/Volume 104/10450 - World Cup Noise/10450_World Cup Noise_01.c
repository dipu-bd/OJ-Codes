#include <stdio.h>

#define SIZE 60

long long fib[SIZE];

int main()
{
    int s, t, n, m = 2;
    fib[0] = 1, fib[1] = 2;

    scanf("%d", &t);
    for(s = 1; t--; ++s)
    {
        scanf("%d", &n);
        for(; n >= m; ++m)
            fib[m] = fib[m - 1] + fib[m - 2];

        printf("Scenario #%d:\n%lld\n\n", s, fib[n]);
    }

    return 0;
}
