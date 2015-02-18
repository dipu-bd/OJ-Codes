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

#define SIZ 100005
int n;
int coin[105];
pii save[105][105][105];

pii recur(int p, int a, int b)
{
    if(p == n) return mp(0, 0);

    pii& dp = save[p][a][b];
    if(dp.fr != -1) return dp;

    int d = a - b;
    if(d == -1)
    {
        dp = recur(p + 1, a + 1, b);
        dp.fr += coin[p];
    }
    else if(d == 1)
    {
        dp = recur(p + 1, a, b + 1);
        dp.sc += coin[p];
    }
    else if(d == 0)
    {
        pii x = recur(p + 1, a + 1, b);
        pii y = recur(p + 1, a, b + 1);
        x.fr += coin[p];
        y.sc += coin[p];
        if(abs(x.fr - x.sc) <= abs(y.fr - y.sc)) dp = x;
        else dp = y;
    }

    return dp;
}

int main()
{
#ifdef LOCAL
    //freopen("1147.inp", "r", stdin);
    //freopen("1147.out", "w", stdout);
#endif // LOCAL

    scanf("%d", &test);
    while(test--)
    {
        int total = 0;

        scanf("%d", &n);
        REP(i, 0, n)
        {
            scanf("%d", coin + i);
            total += coin[i];
        }
        stable_sort(coin, coin + n);

        mem(save, -1);
        pii res = recur(0, 0, 0);
        if(res.fr > res.sc) swap(res.fr, res.sc);

        printf("Case %d: %d %d\n", cas++, res.fr, res.sc);
    }

    return 0;
}
