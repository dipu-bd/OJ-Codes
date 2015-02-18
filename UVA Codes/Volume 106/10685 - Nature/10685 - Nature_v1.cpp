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

#define SIZ 5005

int n, m;
map<string, int> indx;
vii graph[SIZ];
bool vis[SIZ];

int dfs(int u)
{
    if(vis[u]) return 0;
    vis[u] = 1;
    int siz = 1;
    loop(i, graph[u]) siz += dfs(*i);
    return siz;
}

int main()
{
    #ifdef LOCAL
    freopen("10685.inp", "r", stdin);
    #endif // LOCAL

    char name[50];
    while(scanf("%d %d", &n, &m) != EOF && n)
    {
        indx.clear();
        REPE(i, 1, n)
        {
            scanf(" %s", name);
            indx[name] = i;
            graph[i].clear();
        }

        while(m--)
        {
            scanf(" %s", name);
            int& u = indx[name];
            scanf(" %s", name);
            int& v = indx[name];
            graph[u].pb(v);
            graph[v].pb(u);
        }

        clr(vis);
        int msiz = 0;
        REPE(i, 1, n)
        msiz = max(msiz, dfs(i));

        printf("%d\n", msiz);
    }

    return 0;
}
