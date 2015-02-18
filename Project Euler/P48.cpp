#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;
const ll mod = 10000000000LL;

ll cross(ll a, ll b)
{
    const ll mid = 100000LL;
    ll r1 = (a * (b / mid)) % mod;
    ll r2 = (a * (b % mid)) % mod;
    ll res = r2 + (r1 * mid) % mod;
    return (res % mod);
}

ll bigmod(int a, int p)
{
    if(p == 0) return 1LL;

    ll res = bigmod(a, p >> 1);
    res = cross(res, res);
    if(p & 1) res = cross(res, a);
    return res;
}

int main()
{
    ll last = 0;

    for(int i = 1; i <= 1000; ++i)
        last = (last + bigmod(i, i)) % mod;

    printf("%lld\n", last);

    return 0;
}
