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

vii model[25];
pii save[202][22];

pii recur(int m, int n)
{
    if(n < 0) return mp(0, 1);

    pii& dp = save[m][n];
    if(dp.sc != -1) return dp;

    dp = mp(0, 0);
    loop(i, model[n])
    {
        if(*i <= m)
        {
            pii tmp = recur(m - *i, n - 1);
            if(tmp.sc)
            {
                dp.sc = 1;
                dp.fr = max(dp.fr, *i + tmp.fr);
            }
        }
    }

    return dp;
}

int main()
{
#ifdef LOCAL
    freopen("11450.inp", "r", stdin);
#endif // LOCAL

    int m, n, k, x;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &m, &n);

        REP(i, 0, n)
        {
            scanf("%d", &k);
            model[i].clear();
            while(k--)
            {
                scanf("%d", &x);
                model[i].pb(x);
            }
        }

        mem(save, -1);
        pii r = recur(m, n - 1);
        if(r.sc) printf("%d\n", r.fr);
        else puts("no solution");
    }

    return 0;
}
