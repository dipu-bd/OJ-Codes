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

const int inf = 1 << 17;

int n;
int x[18], y[18];
int save[(1 << 16) + 5];

inline bool took(const int& mask, const int& i)
{
    return (mask & (1 << i));
}

inline void takeall(int& t, int& mask, const int& a, const int& b)
{
    REP(i, 0, n)
    if(!took(mask, i))
    {
        if((y[i] - y[a]) * (x[a] - x[b]) ==
                (x[i] - x[a]) * (y[a] - y[b]))
        {
            mask |= 1 << i;
            ++t;
        }
    }
}

int recur(int t = 0, int mask = 0)
{
    if(t == n) return 0;

    int& dp = save[mask];
    if(dp != -1) return dp;

    dp = inf;

    REP(i, 0, n)
    if(!took(mask, i))
    {
        mask |= 1 << i;
        dp = recur(t + 1, mask) + 1;

        REP(j, i + 1, n)
        if(!took(mask, j))
        {
            int l = t + 2;
            int m = mask | (1 << j);
            takeall(l, m, i, j);
            dp = min(dp, recur(l, m) + 1);
        }

        break;
    }

    return dp;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        REP(i, 0, n) scanf("%d %d", x + i, y + i);

        mem(save, -1);
        printf("Case %d: %d\n", cas++, recur());
    }

    return 0;
}
