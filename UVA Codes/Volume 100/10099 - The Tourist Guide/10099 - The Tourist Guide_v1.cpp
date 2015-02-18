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
    int v; //to
    int w; //weight

    edge(int _v = 0, int _w = 0) : v(_v), w(_w) { }
};

#define SIZ 105
const int inf = 1 << 30;
vector<edge> graph[SIZ];
int dist[SIZ];

int maxflow(int s, int d)
{
    clr(dist);
    queue<edge> q;
    q.push(edge(s, inf));
    while(q.size())
    {
        edge e = q.front();
        q.pop();

        loop(it, graph[e.v])
        {
            edge& r = *it;
            int w = min(e.w, r.w);
            if(dist[r.v] < w)
            {
                dist[r.v] = w;
                q.push(edge(r.v, w));
            }
        }
    }

    return dist[d];
}

int main()
{
    #ifdef LOCAL
    freopen("10099.inp", "r", stdin);
    #endif // LOCAL

    int n, r, u, v, w;
    while(scanf("%d %d", &n, &r) != EOF && n)
    {
        while(r--)
        {
            scanf("%d %d %d", &u, &v, &w);
            graph[u].pb(edge(v, w));
            graph[v].pb(edge(u, w));
        }

        scanf("%d %d %d", &u, &v, &w);

        int f = maxflow(u, v) - 1;
        int r = (int)ceil((double)w / f);

        printf("Scenario #%d\n", cas++);
        printf("Minimum Number of Trips = %d\n\n", r);

        REPE(i, 0, n) graph[i].clear();
    }

    return 0;
}
