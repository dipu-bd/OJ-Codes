#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int main()
{
    int test, cas = 1;

    typedef long long ll;
    const ll mod = 10000000000007LL;

    int L, M, N;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d", &L, &M, &N);

        ll sqrl = L * L;
        ll perm = 1LL;
        for(int i = 1; i <= M; ++i, sqrl--)
            perm = (perm * sqrl) % mod;

        ll res = perm;
        for(int i = M + 1; i <= N; ++i, sqrl--)
        {
            perm = (perm * sqrl) % mod;
            res = (res + perm) % mod;
        }

        printf("Case %d: %lld\n", cas++, res);
    }

    return 0;
}
