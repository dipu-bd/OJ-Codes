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
    int u;
    int v;
    int w;
    bool operator < (const edge& rhs) const
    {
        return w < rhs.w;
    }
};

int par[105];
vector<edge> ve;
set<int> path;

void init(int n)
{
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

int MST(int n, int skip = -1)
{
    init(n);

    int rem = n - 1;
    int sum = 0;
    REP(i, 0, ve.size())
    {
        if(rem <= 0) break;
        if(skip == i) continue;

        if(connect(ve[i].u, ve[i].v))
        {
            --rem;
            sum += ve[i].w;
            if(skip == -1) path.insert(i);
        }
    }

    if(rem <= 0) return sum;
    return -1;
}

int main()
{
#ifdef LOCAL
    freopen("10600.inp", "r", stdin);
#endif // LOCAL

    int n, m;
    edge e;

    scanf("%d", &test);
    while(test--)
    {
        ve.clear();
        path.clear();

        scanf("%d %d", &n, &m);
        while(m--)
        {
            scanf("%d %d %d", &e.u, &e.v, &e.w);
            ve.pb(e);
        }

        ssort(ve);

        int fr = MST(n);
        int sc = -1;
        loop(i, path)
        {
            int l = MST(n, *i);
            if(sc == -1) sc = l;
            if(l != -1) sc = min(sc, l);
        }

        printf("%d %d\n", fr, sc);
    }

    return 0;
}
