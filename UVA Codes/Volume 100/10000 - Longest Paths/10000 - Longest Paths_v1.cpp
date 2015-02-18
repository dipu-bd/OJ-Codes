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
    int v;
    int w;

    edge(int a, int b) : v(a), w(b) { }

    bool operator < (const edge& rhs) const
    {
        if(rhs.w == w) return v > rhs.v;
        return w < rhs.w;
    }
};

vii graph[105];
int dist[105];

edge longest(int s)
{
    clr(dist);
    edge res = edge(s, 0);
    queue<edge> q;
    q.push(edge(s, 0));
    while(q.size())
    {
        edge a = q.front();
        q.pop();

        if(res < a) res = a;

        int d = a.w + 1;
        loop(i, graph[a.v])
        {
            if(dist[*i] < d)
            {
                dist[*i] = d;
                q.push(edge(*i, d));
            }
        }
    }

    return res;
}

int main()
{
#ifdef DIPU
    freopen("10000.inp", "r", stdin);
#endif // LOCAL

    int n, s, u, v;
    while(scanf("%d", &n) != EOF && n)
    {
        scanf("%d", &s);
        while(scanf("%d %d", &u, &v) != EOF && u) graph[u].pb(v);

        edge r = longest(s);
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",
               cas++, s, r.w, r.v);

        REPE(i, 0, n) graph[i].clear();
    }

    return 0;
}
