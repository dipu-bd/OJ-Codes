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

struct edge
{
    int u;
    int v;
    int w;
};

int n, m, w;
edge ve[20004];
int dist[1003];
#define INF 0x2f2f2f2f

int main()
{
#ifdef LOCAL
    freopen("558.inp", "r", stdin);
#endif // LOCAL

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &m);

        dist[0] = 0;
        REP(i, 1, n) dist[i] = INF;
        REP(i, 0, m)
        {
            edge& p = ve[i];
            scanf("%d %d %d", &p.u, &p.v, &p.w);
        }

        REP(i, 0, n)
        REP(j, 0, m)
        {
            edge& p = ve[j];
            w = dist[p.u] + p.w;
            if(w < dist[p.v]) dist[p.v] = w;
        }

        bool neg = false;
        REP(i, 0, m)
        {
            edge& p = ve[i];
            w = dist[p.u] + p.w;
            if(dist[p.v] > w)
            {
                neg = true;
                break;
            }
        }

        if(neg) printf("possible\n");
        else printf("not possible\n");
    }

    return 0;
}
