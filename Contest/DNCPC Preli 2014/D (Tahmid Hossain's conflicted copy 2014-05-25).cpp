/*============================
TEAM: SUST_Nexus
CODER: Sudipto Chandra. DIPU
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
typedef long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<int> vii;
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define _a first
#define _b second
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
/*--------------------------------------------------------------------------------------------------*/


typedef map<int, int> mii;
typedef vector<pii> vpp;

#define MOD 1000000007
#define MAX 100001

bool flag[MAX + 10];
vpp factor[MAX + 10];

ll power(ll n, ll p)
{
    if(p == 0) return 1;
    ll r = power(n, p >> 1);
    r = (r * r) % MOD;
    if(p & 1) r = (r * n) % MOD;
    return r;
}

int test, cas = 1;

void mark(int p)
{
    factor[p].pb(mp(p, 1));
    for(int j = p + p; j <= MAX; j += p)
    {
        int t = j, cnt = 0;
        while(!(t % p))
        {
            cnt++;
            t /= p;
        }

        flag[j] = 1;
        factor[j].pb(mp(p, cnt));
    }
}

void sieve()
{
    mark(2);
    for(int i = 3; i < MAX; i += 2)
        if(!flag[i]) mark(i);

}

int main()
{
#ifdef LOCAL
    //freopen(".txt", "r", stdin);
#endif // LOCAL

    sieve();

    int n, x, c;
    ll num, den;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &x);

        mii num, den;
        loop(p, factor[x])
        {
            den[p->_a] = n * p->_b;
        }

        while(n--)
        {
            scanf("%d", &c);
            c = x - c;
            loop(p, factor[c])
            {
                num[p->_a] += p->_b;
            }
        }


        ll n = 1, d = 1;

        loop(p, num)
        {
            int x = den[p->_a];
            int m = min(p->_b, x);
            n = (n * power(p->_a, p->_b - m)) % MOD;
            d = (d * power(p->_a, x - m)) % MOD;
        }
        loop(p, den)
        {
            int x = num[p->_a];
            int m = min(p->_b, x);
            d = (d * power(p->_a, p->_b - m)) % MOD;
            n = (n * power(p->_a, x - m)) % MOD;
        }


        printf("Case %d: ", cas++);

        if(n == 0) printf("0\n");
        else if(n == d) printf("1\n");
        else printf("%lld/%lld\n", n, d);
    }

    return 0;
}

