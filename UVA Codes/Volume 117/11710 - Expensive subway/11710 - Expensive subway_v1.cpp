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
typedef unsigned long long ull;
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
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

struct edge
{
    int u;
    int v;
    int c;
    bool operator < (const edge& e) const
    {
        return c < e.c;
    }
};

int par[500];
vector<edge> ve;
map<string, int> name;

void init(int n)
{
    ve.clear();
    name.clear();
    REPE(i, 0, n) par[i] = i;
}

int getpar(int v)
{
    if(par[v] == v) return v;
    return (par[v] = getpar(par[v]));
}

bool connect(int u, int v)
{
    int pa = getpar(u);
    int pb = getpar(v);
    if(pa == pb) return 0;
    par[pa] = pb;
    return 1;
}

char inp1[20], inp2[20];

int main()
{
#ifdef LOCAL
    freopen("11710.inp", "r", stdin);
#endif // LOCAL

    int n, m;
    edge e;

    while(scanf("%d %d", &n, &m) != EOF && n)
    {
        init(n);

        REPE(i, 1, n)
        {
            scanf(" %s", inp1);
            name[inp1] = i;
        }

        while(m--)
        {
            scanf(" %s %s %d", inp1, inp2, &e.c);
            e.u = name[inp1];
            e.v = name[inp2];
            ve.pb(e);
        }

        scanf(" %s", inp1);

        sort(all(ve));

        ll cost = 0;
        int road = n - 1;
        loop(i, ve)
        {
            if(road == 0) break;

            edge& e = *i;
            if(connect(e.u, e.v))
            {
                --road;
                cost += e.c;
            }
        }

        if(road == 0) printf("%lld\n", cost);
        else printf("Impossible\n");
    }

    return 0;
}
