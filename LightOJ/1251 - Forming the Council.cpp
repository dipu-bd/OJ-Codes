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
//#include <assert.h>
//#define <time.h>
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
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vii;
typedef vector<pii> vpii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define memsz(a,b,n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
#define caseprint(lastchar) printf("Case %d:%c", cas++, lastchar);
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ins insert
#define IT iterator
#define allof(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
//variables and functions
const double PI = 2.0 * acos(0.0);
const double EXP1 = exp(1);
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

#define SIZ 20000
int n, m, nod;
vii graph[SIZ];
vii rgraph[SIZ];
vii stk, ans;
bool vis[SIZ];
int component;
int group[SIZ];

//  1,  2,  3,  4,  5,  6, ...
// -1, +1, -2, +2, -3, +3, ...

inline int complement(int v)
{
    if(v & 1) return v + 1;
    return v - 1;
}

inline int node(int c)
{
    if(c > 0) return (c << 1);
    return node(-c) - 1;
}

inline int member(int v)
{
    return (v >> 1);
}

inline void add(int u, int v)
{
    graph[u].pb(v);
    rgraph[v].pb(u);
}

void dfs1(int u)
{
    if(vis[u]) return;
    vis[u] = 1;
    loop(v, graph[u]) dfs1(*v);
    stk.pb(u);
}

void dfs2(int u)
{
    if(vis[u]) return;
    vis[u] = 1;
    loop(v, rgraph[u]) dfs2(*v);
    group[u] = component;
}

void SCC()
{
    clr(vis);
    stk.clear();
    REPE(i, 1, nod) dfs1(i);

    clr(vis);
    component = 1;
    rloop(v, stk)
    {
        if(!vis[*v])
        {
            dfs2(*v);
            ++component;
        }
    }
}

bool TwoSAT()
{
    SCC();
    ans.clear();
    for(int i = 2; i <= nod; i += 2)
    {
        if(group[i] == group[i - 1]) return false;
        if(group[i] > group[i - 1]) ans.pb(member(i));
    }
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("1251.inp", "r", stdin);
#endif // LOCAL

    int a, b;
    sf1(test);
    while(test--)
    {
        sf2(n, m);

        nod = m << 1;
        while(n--)
        {
            sf2(a, b);
            a = node(a);
            b = node(b);
            add(complement(a), b);
            add(complement(b), a);
        }

        caseprint(' ');
        if(TwoSAT())
        {
            printf("Yes\n");
            printf("%d", (int)ans.size());
            loop(i, ans) printf(" %d", *i);
        }
        else
        {
            printf("No");
        }
        putchar('\n');

        if(test)
        {
            REPE(i, 1, nod)
            {
                graph[i].clear();
                rgraph[i].clear();
            }
        }
    }

    return 0;
}
