/*=========================
 /\u7h0r : 5ud!p70 ch@ndr@
 ==========================*/
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
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i >= n; --i)
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

struct edge
{
    int u;
    int v;
    int w;
};

#define NSIZ 210
int busy[NSIZ];
int dist[NSIZ];
bool reach[NSIZ];
vector<edge> ve;
vii graph[NSIZ];

inline int cube(int x)
{
    return x * x * x;
}

void dfs(int u)
{
    if(reach[u]) return;
    reach[u] = 1;
    loop(v, graph[u]) dfs(*v);
}

     int main()
{
#ifdef LOCAL
    freopen("1074.inp", "r", stdin);
#endif // LOCAL

    edge e;
    int n, m, q, x;

    scanf("%d", &test);
    while(test--)
    {
        ve.clear();
        clr(reach);
        mem(dist, 0x2f);

        scanf("%d", &n);
        REPE(i, 1, n)
        {
            graph[i].clear();
            scanf("%d", busy + i);
        }

        scanf("%d", &m);
        while(m--)
        {
            scanf("%d %d", &e.u, &e.v);
            e.w = cube(busy[e.v] - busy[e.u]);
            ve.pb(e);
            graph[e.u].pb(e.v);
        }

        dfs(1);
        dist[1] = 0;
        REP(i, 1, n)
        {
            loop(it, ve)
            {
                dist[it->v] = min(dist[it->v], dist[it->u] + it->w);
            }
        }

        printf("Case %d:\n", cas++);

        scanf("%d", &q);
        while(q--)
        {
            scanf("%d", &x);
            int d = dist[x];
            if(d < 3 || !reach[x]) puts("?");
            else printf("%d\n", d);
        }
    }

    return 0;
}
