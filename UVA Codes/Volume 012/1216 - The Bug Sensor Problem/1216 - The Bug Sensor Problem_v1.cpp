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
typedef long long LL;
typedef unsigned long long ULL;
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
#define NL putchar('\n')
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

struct edge
{
    int u, v;
    double w;
    bool operator < (const edge& r)const
    {
        return w < r.w;
    }
};

int n;
int* par;
vector<pii> point;
vector<edge> ve;

double sqrsum(double x, double y)
{
    return x * x + y * y;
}

double dist(pii& a, pii& b)
{
    return sqrt(sqrsum(a.fr - b.fr, a.sc - b.sc));
}

void make_edge()
{
    ve.clear();
    n = point.size();

    edge e;
    REP(i, 0, n)
    REP(j, i + 1, n)
    {
        e.u = i;
        e.v = j;
        e.w = dist(point[i], point[j]);
        ve.pb(e);
    }

    ssort(ve);
}

void init()
{
    if(par) delete par;
    par = new int[n + 10];
    REPE(i, 0, n) par[i] = i;
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
    freopen("1216.inp", "r", stdin);
#endif // LOCAL

    int u, v, m;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &m);

        point.clear();
        while(scanf("%d", &u) != EOF)
        {
            if(u == -1) break;
            scanf("%d", &v);
            point.pb(mp(u, v));
        }

        make_edge();
        init();

        double res = 0;
        int rem = n;
        loop(i, ve)
        {
            if(rem == m) break;
            if(connect(i->u, i->v))
            {
                res = i->w;
                --rem;
            }
        }

        res = ceil(res);
        printf("%.0lf\n", res);
    }

    return 0;
}
