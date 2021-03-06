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

#define SIZ 110
int stage[SIZ];
int edge[SIZ];

int main()
{
#ifdef LOCAL
    freopen("12376.inp", "r", stdin);
#endif // LOCAL

    int n, m, u, v;

    scanf("%d", &test);
    while(test--)
    {
        mem(edge, -1);

        scanf("%d %d", &n, &m);
        REP(i, 0, n) scanf("%d", stage + i);

        while(m--)
        {
            scanf("%d %d", &u, &v);
            if(edge[u] == -1) edge[u] = v;
            else if(stage[edge[u]] < stage[v]) edge[u] = v;
        }

        int cur = 0;
        int unit = stage[cur];
        while(edge[cur] != -1)
        {
            cur = edge[cur];
            unit += stage[cur];
        }

        printf("Case %d: %d %d\n", cas++, unit, cur);
    }

    return 0;
}
