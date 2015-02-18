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

#define SIZ 105

int n;
char name[SIZ][100];
map<string, int> indx;
vii graph[SIZ];
int indeg[SIZ];
bool visit[SIZ];
vii topver;

void topsort()
{
    clr(visit);
    topver.clear();

    while(topver.size() < n)
    {
        REPE(u, 1, n)
        {
            if(!visit[u] && !indeg[u])
            {
                loop(v, graph[u]) if(indeg[*v]) --indeg[*v];
                visit[u] = 1;
                topver.pb(u);
                break;
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("11060.inp", "r", stdin);
#endif // LOCAL

    int m, a, b;

    while(scanf("%d", &n) != EOF)
    {
        clr(indeg);
        indx.clear();
        REPE(i, 1, n) graph[i].clear();

        REPE(i, 1, n)
        {
            scanf(" %s", name[i]);
            indx[name[i]] = i;
        }

        scanf("%d", &m);
        while(m--)
        {
            scanf(" %s %s", name[SIZ - 1], name[SIZ - 2]);
            a = indx[name[SIZ - 1]];
            b = indx[name[SIZ - 2]];
            graph[a].pb(b);
            ++indeg[b];
        }

        topsort();

        printf("Case #%d: Dilbert should drink beverages in this order:", cas++);
        loop(i, topver) printf(" %s", name[*i]);
        printf(".\n\n");
    }

    return 0;
}
