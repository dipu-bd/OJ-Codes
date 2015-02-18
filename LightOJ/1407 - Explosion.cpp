/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
//#include <bits/stdc++.h>
//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
//#include <assert.h>
//#include <time.h>
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
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
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
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
//variables and functions
const double PI = 2.0 * acos(0.0);
const double EXP1 = exp(1);
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

#define SIZ 2014

int nod;
vii stk;
int n, m, k;
vii graph[SIZ];
vii rgraph[SIZ];
bool ans[SIZ];
bool vis[SIZ];
int group[SIZ];
int component;
int memch[10][5];

//  1,  2,  3,  4,  5,  6, ...
// -1, +1, -2, +2, -3, +3, ...

inline void connect(int u, int v)
{
    graph[u].pb(v);
    rgraph[v].pb(u);
}

void buildgraph(int type, int x, int y)
{
    int ac = x << 1;
    int a = ac - 1;
    int bc = y << 1;
    int b = bc - 1;
    if(type == 1)
    {
        connect(ac, b);
        connect(bc, a);
    }
    else if(type == 2)
    {
        connect(ac, bc);
        connect(b, a);
    }
    else if(type == 3)
    {
        connect(a, bc);
        connect(b, ac);
    }
    else
    {
        connect(a, bc);
        connect(bc, a);
        connect(ac, b);
        connect(b, ac);
    }
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
    component = 0;
    rloop(v, stk)
    {
        if(!vis[*v])
        {
            ++component;
            dfs2(*v);
        }
    }
}

bool TwoSAT()
{
    SCC();
    for(int i = 2; i <= nod; i += 2)
    {
        if(group[i] == group[i - 1]) return false;
        ans[i >> 1] = (group[i] < group[i - 1]);
    }
    return true;
}

bool ThreeSAT()
{
    REP(i, 0, k)
    {
        int type = memch[i][0];
        int x = memch[i][1];
        int y = memch[i][2];
        int z = memch[i][3];

        if(type == 1)
        {
            if(!(ans[x] || ans[y] || ans[z]))
                return false;
        }
        else
        {
            if(ans[x] && ans[y] && ans[z])
                return false;
        }
    }
    return true;
}

void init()
{
    nod = n << 1;
    REPE(i, 1, nod)
    {
        graph[i].clear();
        rgraph[i].clear();
    }
}

int main()
{
#ifdef LOCAL
    freopen("1407.inp", "r", stdin);
#endif // LOCAL

    int type, x, y;

    sf1(test);
    while(test--)
    {
        sf3(n, m, k);
        init();

        //get oracle's choices
        while(m--)
        {
            sf3(type, x, y);
            buildgraph(type, x, y);
        }

        //get member's choice
        REP(i, 0, k)
        {
            REP(j, 0, 4)
            sf1(memch[i][j]);
        }

        bool sat = TwoSAT();
        if(sat) sat = ThreeSAT();

        printf("Case %d: ", cas++);
        if(!sat)
        {
            printf("Impossible.\n");
            continue;
        }

        printf("Possible ");

        vii res;
        REPE(i, 1, nod)
        if(ans[i]) res.pb(i);

        printf("%d", (int)res.size());
        loop(i, res) printf(" %d", *i);
        printf(".\n");
    }

    return 0;
}
