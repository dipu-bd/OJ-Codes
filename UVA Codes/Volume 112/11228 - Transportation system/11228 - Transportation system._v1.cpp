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
typedef unsigned long long ull;
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
#define LB lower_bound
#define UB upper_bound
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

struct edge
{
    int u;
    int v;
    double w;

    bool operator < (const edge& e) const
    {
        return w < e.w;
    }
};

#define SIZ 1010
int par[SIZ];
pii point[SIZ];
vector<edge> ve;

double sqr(double x)
{
    return x * x;
}

double dist(const pii& a, const pii& b)
{
    return sqrt(sqr(a.fr - b.fr) + sqr(a.sc - b.sc));
}

void init(int n)
{
    ve.clear();
    REPE(i, 1, n) par[i] = i;

    edge e;
    REPE(i, 1, n)
    REPE(j, i + 1, n)
    {
        e.u = i;
        e.v = j;
        e.w = dist(point[i], point[j]);
        ve.pb(e);
    }

    ssort(ve);
}

int getpar(int v)
{
    if(v == par[v]) return v;
    return (par[v] = getpar(par[v]));
}

bool connect(int u, int v)
{
    int pu = getpar(u);
    int pv = getpar(v);
    if(pu == pv) return 0;
    par[pu] = pv;
    return 1;
}

int main()
{
#ifdef LOCAL
    freopen("11228.inp", "r", stdin);
#endif // LOCAL

    int n, r;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &r);

        REPE(i, 1, n)
        scanf("%d %d", &point[i].fr, &point[i].sc);

        init(n);
        int state = 1;
        double road = 0;
        double rail = 0;
        loop(i, ve)
        {
            if(connect(i->u, i->v))
            {
                if(i->w <= r) road += i->w;
                else rail += i->w, ++state;
            }
        }

        printf("Case #%d: %d %.0lf %.0lf\n", cas++, state, road, rail);
    }

    return 0;
}
