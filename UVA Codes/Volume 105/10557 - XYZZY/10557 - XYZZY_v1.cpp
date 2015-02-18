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

struct edge
{
    int u;
    int v;
    int w;
};

#define SIZ 105
int energy[SIZ];
vii graph[SIZ];
int dist[SIZ];
bool vis[SIZ];
vector<edge> ve;

void dfs(int u)
{
    vis[u] = 1;
    loop(i, graph[u]) if(!vis[*i]) dfs(*i);
}

int main()
{
#ifdef LOCAL
    freopen("10557.inp", "r", stdin);
#endif // LOCAL

    edge e;
    int n, m, v;

    while(scanf("%d", &n) != EOF)
    {
        if(n == -1) break;

        REPE(u, 1, n)
        {
            scanf("%d", &energy[u]);
            scanf("%d", &m);
            graph[u].clear();
            while(m--)
            {
                scanf("%d", &v);
                graph[u].pb(v);
            }
        }

        if(n == 1)
        {
            printf("winnable\n");
            continue;
        }

        ve.clear();
        REPE(i, 1, n)
        {
            e.u = i;
            loop(j, graph[i])
            {
                e.v = *j;
                e.w = energy[e.v];
                ve.pb(e);
            }
        }

        mem(dist, 0x80);
        dist[1] = 100;
        REPE(i, 2, n)
        {
            loop(it, ve)
            {
                e = *it;
                m = dist[e.u] + e.w;
                if(dist[e.v] < m && m > 0) dist[e.v] = m;
            }
        }

        if(dist[n] > 0)
        {
            puts("winnable");
            continue;
        }

        bool win = 1;
        loop(it, ve)
        {
            e = *it;
            m = dist[e.u] + e.w;
            if(dist[e.v] < m && m > 0)
            {
                clr(vis);
                dfs(e.u);
                win = vis[n];
                break;
            }
            if(m <= 0)
            {
                win = 0;
                break;
            }
        }

        if(win) printf("winnable\n");
        else printf("hopeless\n");
    }

    return 0;
}
