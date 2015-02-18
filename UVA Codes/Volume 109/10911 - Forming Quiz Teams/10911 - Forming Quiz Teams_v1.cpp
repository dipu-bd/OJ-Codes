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
//#include <assert.h>
//#define <time.h>
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
typedef vector<int> vii;
typedef vector<pii> vpii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define memsz(a,b,n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
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
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
//variables and functions
const double PI = 2.0 * acos(0.0);
const double EXP1 = exp(1);
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

int n;
int x[20];
int y[20];
char name[20][30];
double save[65555];

double recur(int state)
{
    double& dp = save[state];
    if(dp > 0) return dp;

    dp = INT_MAX;
    bool res = true;
    for(int i = 0, m = 1; i < n; ++i, m <<= 1)
    {
        if(!(state & m))
        {
            for(int j = i + 1, l = m << 1; j < n; ++j, l <<= 1)
            {
                if(!(state & l))
                {
                    dp = min(dp, recur((state | m) | l)
                             + hypot(x[i] - x[j], y[i] - y[j]));
                    res = false;
                }
            }
        }
    }

    if(res) dp = 0;
    return dp;
}

int main()
{
#ifdef LOCAL
    freopen("10911.inp", "r", stdin);
#endif // LOCAL

    while(sf1(n) == 1 && n)
    {
        n <<= 1;
        REP(i, 0, n)
        {
            scanf(" %s", name[i]);
            sf2(x[i], y[i]);
        }

        clr(save);
        double res = recur(0);
        printf("Case %d: %.2lf\n", cas++, res);
    }

    return 0;
}
