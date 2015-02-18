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

int des, n;
bool vis[105];
int graph[105][105];

bool dfs(int v, int m)
{
    if(vis[v]) return 0;
    if(v == des) return 1;

    vis[v] = 1;
    REPE(i, 1, n)
    if(graph[v][i])
    {
        if(dfs(i))
        {
            graph[i][v] += graph[v][i];
        }
    }

    return 0;
}

int maxflow(int s, int t)
{
    des = t;
    int res = 0;
    while(1)
    {
        clr(vis);
        t = dfs(s);
        if(t == 0) break;
        res += t;
    }

    REPE(i, 1, n) res += graph[t][i];
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int s, t, m;
    int u, v, c;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        scanf("%d %d %d", &s, &t, &m);

        clr(graph);
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &c);
            graph[u][v] = graph[v][u] = c;
        }

        int res = maxflow(s, t);
        printf("Case %d: %d\n", cas++, res);
    }

    return 0;
}
