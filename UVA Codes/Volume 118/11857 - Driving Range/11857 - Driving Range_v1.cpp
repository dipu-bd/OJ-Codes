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
    bool operator < (const edge& ed) const
    {
        return c < ed.c;
    }
};

#define SIZ 1000000
int par[SIZ + 10];
vector<edge> ve;

void init(int n)
{
    REPE(i, 0, n) par[i] = i;
}

int getpar(int v)
{
    if(v == par[v]) return v;
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

int main()
{
    #ifdef LOCAL
    //freopen("", "r", stdin);
    #endif // LOCAL

    int n, m;
    edge e;

    while(scanf("%d %d", &n, &m) != EOF && n)
    {
        init(n);
        ve.clear();

        while(m--)
        {
            scanf("%d %d %d", &e.u, &e.v, &e.c);
            ve.push_back(e);
        }

        sort(all(ve));

        int last;
        int road = n - 1;
        loop(i, ve)
        {
            if(road == 0) break;

            edge& e = *i;
            if(connect(e.u, e.v))
            {
                last = e.c;
                --road;
            }
        }

        if(road == 0) printf("%d\n", last);
        else printf("IMPOSSIBLE\n");
    }

    return 0;
}
