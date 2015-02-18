#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define MOD 10000000
typedef long long ll;

int bigmod(int n, int p, int m)
{
    if(p == 0) return 1;
    ll res = bigmod(n , p >> 1, m);
    res = (res * res) % m;
    return (p & 1) ? (res * n) % m : res;
}

int getlead(int n, int p)
{
    double x = p * log10(n);
    double res = pow(10.0, x - floor(x));
    return (int)(res * 100);
}

int main()
{
    int test, cas = 1;
    int n, k;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &k);
        int trail = bigmod(n, k, MOD) % 1000;
        int lead = getlead(n, k);

        printf("Case %d: ", cas++);
        printf("%.3d %.3d\n", lead, trail);
    }

    return 0;
}
