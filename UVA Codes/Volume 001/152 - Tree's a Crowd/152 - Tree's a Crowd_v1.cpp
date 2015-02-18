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

inline int sqr(int x) { return x * x; }

struct point
{
    int x;
    int y;
    int z;
    point() { }

    int operator - (const point& p) const
    {
        return (int)floor(sqrt(sqr(x - p.x) + sqr(y - p.y) + sqr(z - p.z)));
    }
};

int unit[10];
vector<point> ve;

int main()
{
#ifdef LOCAL
    freopen("152.inp", "r", stdin);
#endif // LOCAL

    point p;
    while(scanf("%d %d %d", &p.x, &p.y, &p.z) != EOF)
    {
        if(!(p.x || p.y || p.z)) break;
        ve.pb(p);
    }

    REP(i, 0, ve.size())
    {
        int close = 10;
        REP(j, 0, ve.size())
        if(i != j)
        {
            int d = ve[i] - ve[j];
            close = min(d, close);
        }
        if(close < 10) ++unit[close];
    }

    REP(i, 0, 10) printf("%4d", unit[i]);
    putchar('\n');

    return 0;
}
