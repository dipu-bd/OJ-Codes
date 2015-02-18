/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef long long ll;

int main()
{
    ll n;
    while(scanf("%lld", &n) != EOF && n)
    {
        ll res = n - (int)sqrt(n) - (int)sqrt(n >> 1);
        printf("%lld\n", res);
    }

    return 0;
}
