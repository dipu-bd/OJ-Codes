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
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        ll n;
        scanf("%lld", &n);
        ll res = n - (int)sqrt(n) - (int)sqrt(n >> 1);
        printf("Case %d: %lld\n", cas++, res);
    }

    return 0;
}

