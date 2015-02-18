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
typedef pair<int, int> pii;
typedef vector<int> vii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB(v, x) lower_bound(v.begin(), v.end(), x)
#define UB(v, x) upper_bound(v.begin(), v.end(), x)
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

#define SIZ 10000004
#define PSIZ 664600
int sz;
int primes[PSIZ];
char flag[1 + (SIZ >> 4)];

#define GET(i) (flag[(i) >> 3] & (1 << ((i) & 7)))
#define SET(i) (flag[(j) >> 3] |= (1 << ((j) & 7)))
#define isprime(i) (i == 2 || (((i) & 1) && !GET((i) >> 1)))

void sieve()
{
    int i, j, l, s;

    l = (int)sqrt(SIZ) >> 1;
    s = SIZ >> 1;
    flag[0] = 0b10010001;

    for(i = 1; i < l; ++i)
        if(!GET(i))
            for(j = (i << 1) * (i + 1); j < s; j += i + i + 1)
                SET(j);
}

void precalc()
{
    sieve();

    sz = 0;
    primes[sz++] = 2;

    for(int i = 3; i < SIZ; i += 2)
        if(!(flag[i >> 4] & (1 << ((i>>1) & 7))))
            primes[sz++] = i;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    precalc();

    ll n, res;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%lld", &n);

        res = 1;
        ll m = sqrt(n);
        REP(i, 0, sz)
        {
            int p = primes[i];
            if(p > m) break;
            if(!(n % p))
            {
                int cnt = 0;
                do
                {
                    ++cnt;
                    n /= p;
                }
                while(!(n % p));
                m = sqrt(n);
                res *= (cnt << 1) + 1;
            }
        }

        if(n > 1) res *= 3;
        res = (res + 1) >> 1;

        printf("Case %d: %lld\n", cas++, res);
    }

    return 0;
}

