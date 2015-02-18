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

ll logpow(ll a, ll b)
{
    if(b == 0) return 1;

    ll res = logpow(a, b >> 1);
    res = res * res;
    if(b & 1) res = res * a;

    return res;
}

int main()
{
#ifdef LOCAL
    freopen("107.inp", "r", stdin);
#endif // LOCAL

    ll p, q, n, m, l, h, t;
    while(scanf("%lld %lld", &p, &q) != EOF && p)
    {
        if(q == 1)
        {
            l = log2(p);
            h = 2 * p  - 1;
        }
        else
        {
            for(m = 1; m < 70; ++m)
            {
                n = (ll)round(pow(q, 1.0 / m));
                t = logpow(n + 1, m);
                if(t == p && logpow(n, m) == q) break;
            }

            l = (q - 1) / (n - 1);
            h = p * (t + (t - q) * n) / t;
        }

        printf("%lld %lld\n", l, h);
    }

    return 0;
}
