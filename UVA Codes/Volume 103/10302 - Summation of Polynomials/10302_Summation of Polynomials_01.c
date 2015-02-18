#include <stdio.h>

int main()
{
    long long int n, r;
    while(scanf("%lld",&n)!=EOF)
    {
        r = n * n;
        r = r * (r + n + n + 1);
        r /= 4;

        printf("%lld\n", r);
    }

    return 0;
}
