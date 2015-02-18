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

#define SIZ 102
vii graph[SIZ];
bool vis[SIZ];

void dfs(int u)
{
    if(vis[u]) return;
    vis[u] = 1;
    loop(v, graph[u]) dfs(*v);
}

int component(int n)
{
    int cnt = 0;
    REPE(i, 1, n) if(!vis[i]) {++cnt; dfs(i); }
    return cnt;
}

int main()
{
#ifdef LOCAL
    freopen("315.inp", "r", stdin);
#endif // LOCAL

    int n, u, v;
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0) break;

        while(scanf("%d", &u) != EOF)
        {
            if(u == 0) break;
            while(getchar() == ' ')
            {
                scanf("%d", &v);
                graph[u].pb(v);
                graph[v].pb(u);
            }
        }

        clr(vis);
        int init = component(n);

        int cnt = 0;
        REPE(i, 1, n)
        {
            clr(vis);
            vis[i] = 1;
            if(component(n) != init) cnt++;
        }

        printf("%d\n", cnt);

        REPE(i, 0, n) graph[i].clear();
    }

    return 0;
}
