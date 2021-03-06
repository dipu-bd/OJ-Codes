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

double x, y, c;

double equation(double w)
{
    double a = sqrt(x * x - w * w);
    double b = sqrt(y * y - w * w);
    return (a + b) * c - a * b;
}

double solve()
{
    double xmax, xmin, mid, res;
    const double EPS = 1e-10;
    const double ZERO = 1e-5;

    xmin = 0;
    xmax = x < y ? x : y;
    while(xmin < xmax)
    {
        mid = 0.5 * (xmax + xmin);
        res = equation(mid);
        if(res < 0) xmin = mid + EPS;
        if(res > 0) xmax = mid - EPS;
        if(fabs(res) < ZERO) break;
    }

    return mid;
}

int main()
{
#ifdef LOCAL
    freopen("10566.inp", "r", stdin);
#endif // LOCAL

    while(scanf("%lf %lf %lf", &x, &y, &c) != EOF)
    {
        double w = solve();
        printf("%.3lf\n", w);
    }

    return 0;
}
