#include <stdio.h>

int powerMod(int n, int p)
{
    if(n<=0) return 1;
    return ((10 % p) * powerMod(n-1, p)) % p;
}

int main()
{
    int n,p, mod;
    long long int m;
    while(scanf("%d", &p)!=EOF)
    {
        for(mod=1%p, n=1; mod; ++n)
            mod = (mod + powerMod(n, p)) % p;
        printf("%d\n", n);
    }

    return 0;
}
