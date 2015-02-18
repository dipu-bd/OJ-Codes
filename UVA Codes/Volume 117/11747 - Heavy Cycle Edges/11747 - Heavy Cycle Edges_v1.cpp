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

#define SIZ 1005

struct edge
{
    int u;
    int v;
    int w;
    bool operator <(const edge& r) const
    {
        return w < r.w;
    }
};

int par[SIZ];
vii heavy;
vector<edge> ve;

void init(int n)
{
    ve.clear();
    heavy.clear();
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
    freopen("11747.inp", "r", stdin);
#endif // LOCAL

    int n, m;
    edge e;

    while(scanf("%d %d", &n, &m) != EOF)
    {
        if(n == 0) break;

        init(n);
        while(m--)
        {
            scanf("%d %d %d", &e.u, &e.v, &e.w);
            ve.pb(e);
        }

        ssort(ve);

        loop(i, ve)
        {
            if(!connect(i->u, i->v))
                heavy.pb(i->w);
        }

        ssort(heavy);

        loop(i, heavy)
        {
            if(i != heavy.begin()) putchar(' ');
            printf("%d", *i);
        }

        if(heavy.empty())
            printf("forest");

        putchar('\n');
    }

    return 0;
}
