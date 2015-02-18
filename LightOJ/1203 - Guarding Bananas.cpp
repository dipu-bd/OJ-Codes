/*=========================
 /\u7h0r : 5ud!p70 ch@ndr@
 ==========================*/
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
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i >= n; --i)
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

const double PI = 2 * acos(0);

struct point
{
    ll x;
    ll y;
    point(ll a = 0, ll b = 0) : x(a), y(b) { }

    bool operator < (const point& r) const
    {
        return (y == r.y) ? (x < r.x) : (y < r.y);
    }
};

int bindx;
point base;
vii sorted;
vector<point> init;
vector<point> convex;

void clearall()
{
    init.clear();
    sorted.clear();
    convex.clear();
    base = point(INT_MAX, INT_MAX);
}

inline ll direction(const point& b, const point& f, const point& t)
{
    return (t.x - b.x) * (f.y - b.y) -
           (t.y - b.y) * (f.x - b.x);
}

inline ll diff(const point& a, const point& b)
{
    return (a.x - b.x) * (a.x - b.x) +
           (a.y - b.y) * (a.y - b.y);
}

inline double dist(const point& a, const point& b)
{
    return sqrt((double)diff(a, b));
}

inline ll dott(const point& b, const point& f, const point& t)
{
    return (f.x - b.x) * (t.x - b.x) +
           (f.y - b.y) * (t.y - b.y);
}

inline bool compare(const int& a, const int& b)
{
    return direction(base, init[a], init[b]) < 0;
}

void sortpoint()
{
    vii::iterator p;
    REP(i, 0, init.size())
    {
        p = lower_bound(all(sorted), i, compare);
        if(p == sorted.end()) sorted.pb(i);
        else if(compare(*p, i)) sorted.insert(p + 1, i);
        else if(compare(i, *p)) sorted.insert(p, i);
        else if(diff(base, init[*p]) < diff(base, init[i])) *p = i;
    }
    sorted.insert(sorted.begin(), bindx);
}

double convexhull()
{
    loop(i, sorted)
    {
        point& p = init[*i];
        while(convex.size() >= 3)
        {
            point& a = *(convex.end() - 2);
            point& b = *(convex.end() - 1);
            if(direction(b, p, a) < 0) break;
            convex.pop_back();
        }
        convex.push_back(p);
    }
}

double angle(const point& b, const point& f, const point& t)
{
    //dott product of (BF) and (BT) vectors
    double dt = dott(b, f, t);
    double ft = dist(f, b) * dist(t, b);
    double res = acos(dt / ft);
    if(res < 0) res += 2 * PI;
    return res;
}

double minangle()
{
    int n = convex.size();
    if(n < 3) return 0;

    double res = INT_MAX;
    REP(i, 0, n)
    {
        point& a = convex[i];
        point& b = convex[(i + 1) % n];
        point& c = convex[(i + 2) % n];
        double d = angle(b, a, c);
        if(d < res) res = d;
    }
    return res;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int n;
    point p;

    scanf("%d", &test);
    while(test--)
    {
        clearall();

        scanf("%d", &n);
        while(n--)
        {
            scanf("%lld %lld", &p.x, &p.y);
            init.pb(p);
            if(p < base)
            {
                base = p;
                bindx = init.size() - 1;
            }
        }

        sortpoint();
        convexhull();

        double res = minangle();
        res = (res * 180 / PI);

        printf("Case %d: %.8lf\n", cas++, res);
    }

    return 0;
}
