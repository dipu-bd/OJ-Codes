
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

#define SIZ 10004

int n, m;
vii topver;
vii graph[SIZ];
bool visit[SIZ];

void topsort(int v)
{
    if(visit[v]) return;
    visit[v] = 1;
    loop(i, graph[v]) topsort(*i);
    topver.pb(v);
}

void dfs(int v)
{
    if(visit[v]) return;
    visit[v] = 1;
    loop(i, graph[v]) dfs(*i);
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int u, v;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &m);

        topver.clear();
        REPE(i, 0, n) graph[i].clear();

        while(m--)
        {
            scanf("%d %d", &u, &v);
            graph[u].pb(v);
        }

        clr(visit);
        REPE(i, 1, n) topsort(i);

        clr(visit);
        int res = 0;
        rloop(it, topver)
        {
            if(!visit[*it])
            {
                dfs(*it);
                ++res;
            }
        }

        printf("Case %d: %d\n", cas++, res);
    }

    return 0;
}
