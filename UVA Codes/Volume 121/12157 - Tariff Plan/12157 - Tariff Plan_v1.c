#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("12157.inp", "r", stdin);
#endif

    int t, n, p, a, b, i;
    scanf("%d", &t);
    for(i = 1; t--; ++i)
    {
        scanf("%d", &n);
        a = b = 0;
        while(n--)
        {
            scanf("%d", &p);
            a += (1 + p / 30) * 10;
            b += (1 + p / 60) * 15;
        }

        if(a < b) printf("Case %d: Mile %d\n", i, a);
        else if(b < a) printf("Case %d: Juice %d\n", i, b) ;
        else printf("Case %d: Mile Juice %d\n", i, a);
    }

    return 0;
}
