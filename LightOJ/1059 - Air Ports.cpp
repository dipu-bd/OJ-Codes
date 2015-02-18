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
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define _a first
#define _b second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define _IT ::iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(all(v))
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)

struct edge
{
    int u;
    int v;
    int c;

    bool operator < (const edge& rhs) const
    {
        return c < rhs.c;
    }
};

int par[10010];

void init(int n)
{
    REPE(i, 0, n) par[i] = i;
}

int getpar(int v)
{
    if(v == par[v]) return v;
    return par[v] = getpar(par[v]);
}

bool connect(int u, int v)
{
    int pu = getpar(u);
    int pv = getpar(v);
    if(par[pu] == par[pv]) return false;
    par[pu] = par[pv];
    return true;
}

int main()
{
    int test, cas = 1;

    edge e;
    int n, m, a;

    scanf("%d", &test);
    while(test--)
    {
        vector<edge> road;

        //take input
        scanf("%d %d %d", &n, &m, &a);
        while(m--)
        {
            scanf("%d %d %d", &e.u, &e.v, &e.c);
            road.pb(e);
        }

        init(n);
        sort(all(road));

        //run mst
        ll cost = 0;
        int airport = n;
        int minport = n;
        ll mincost = (ll)a * n;
        loop(i, road)
        {
            edge& e = *i;
            if(connect(e.u, e.v))
            {
                cost += e.c;
                --airport;

                ll tmp = cost + (ll)a * airport;
                if(tmp < mincost)
                {
                    mincost = tmp;
                    minport = airport;
                }
            }
        }

        //print res
        printf("Case %d: %lld %d\n", cas++, mincost, minport);
    }

    return 0;
}
