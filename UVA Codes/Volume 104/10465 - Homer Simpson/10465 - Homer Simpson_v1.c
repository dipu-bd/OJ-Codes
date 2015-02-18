#include <stdio.h>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("10465.inp", "r", stdin);
#endif

    int m, n, t, p, q, c, d, r, res;
    while(scanf("%d %d %d", &m, &n, &t) != EOF)
    {
        for(c = res = 0; t > c; ++c)
        {
            d = t - c;

            for(q = 0, r = q * n; r < d; ++q, r = q * n )
                if(!((d - r) % m))
                {
                    p = (d - r) / m;
                    r = p + q;
                    if(r > res) res = r;
                }

            for(p = 0, r = p * m; r < d; ++p, r = p * m)
                if(!((d - r) % n))
                {
                    q = (d - r) / n;
                    r = p + q;
                    if(r > res) res = r;
                }

            if(res) break;
        }

        if(c) printf("%d %d\n", res, c);
        else printf("%d\n", res);

    }

    return 0;
}
