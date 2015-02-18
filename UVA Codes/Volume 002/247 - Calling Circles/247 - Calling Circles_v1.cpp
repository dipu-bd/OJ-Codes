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

#define SIZ 30

int n, m;
char names[SIZ][SIZ];
map<string, int> indx;
vii graph[SIZ];
vii revg[SIZ];
vii qu;
vii strong;
char vis[SIZ];

void topsort(int v)
{
    if(vis[v]) return;
    vis[v] = 1;
    loop(i, graph[v]) topsort(*i);
    qu.pb(v);
}

void dfs(int u)
{
    if(vis[u]) return;
    vis[u] = 1;
    loop(i, revg[u]) dfs(*i);
    strong.pb(u);
}

int main()
{
#ifdef LOCAL
    freopen("247.inp", "r", stdin);
#endif // LOCAL

    while(scanf("%d %d", &n, &m) != EOF && n)
    {
        indx.clear();
        REPE(i, 0, n)
        {
            graph[i].clear();
            revg[i].clear();
        }

        int ix = 1;
        while(m--)
        {
            scanf(" %s", names[ix]);
            int& u = indx[names[ix]];
            if(u == 0) u = ix++;

            scanf(" %s", names[ix]);
            int& v = indx[names[ix]];
            if(v == 0) v = ix++;

            graph[u].pb(v);
            revg[v].pb(u);
        }

        clr(vis);
        qu.clear();
        REPE(i, 1, n) topsort(i);

        if(cas > 1) putchar('\n');
        printf("Calling circles for data set %d:\n", cas++);

        clr(vis);
        rloop(i, qu)
        {
            if(vis[*i]) continue;
            strong.clear();
            dfs(*i);
            loop(j, strong)
            {
                if(j != strong.begin())
                    printf(", ");
                printf("%s", names[*j]);
            }
            putchar('\n');
        }
    }

    return 0;
}
