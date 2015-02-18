/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
//cpp headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <list>
//#include <bitset>
using namespace std;
//typedefs
typedef long long ll;

int test, cas = 1;

//sequence repeats after fm(300)

int sum[305];
int fibmod[305];
void precalc()
{
    sum[0] = 1;
    sum[1] = 2;
    fibmod[0] = 1;
    fibmod[1] = 1;
    for(int i = 2; i <= 300; ++i)
    {
        fibmod[i] = (fibmod[i - 1] + fibmod[i - 2]) % 100;
        sum[i] = sum[i - 1] + fibmod[i];
    }
}

int main()
{
#ifdef LOCAL
    freopen("12620.inp", "r", stdin);
    freopen("12620.out", "w", stdout);
#endif // LOCAL

    precalc();

    scanf("%d", &test);
    while(test--)
    {
        ll n, m;
        scanf("%lld %lld", &n, &m);

        int p = (n - 1) % 300;
        int q = (m - 1) % 300;
        ll d = llabs(m - n) / 300;
        if(q < p) d++;

        ll res = (sum[q] - sum[p - 1]) + d * sum[299];

        printf("%lld\n", res);
    }

    return 0;
}
