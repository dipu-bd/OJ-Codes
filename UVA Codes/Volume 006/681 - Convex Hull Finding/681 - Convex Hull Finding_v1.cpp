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

struct point
{
    ll x;
    ll y;

    point(ll a = 0, ll b = 0) : x(a), y(b) { }

    bool operator < (const point& r) const
    {
        if(y != r.y) return y < r.y;
        return x < r.x;
    }

    ll diff(const point& r) const
    {
        double xd =  x - r.x;
        double yd =  y - r.y;
        return xd * xd + yd * yd;
    }
};

point base;
vector<point> init;
vector<point> sorted;
vector<point> convex;

ll direction(point o, point f, point t)
{
    return (t.x - o.x) * (f.y - o.y) -
           (t.y - o.y) * (f.x - o.x);
}

bool compare(const point& a, const point& b)
{
    return direction(base, a, b) < 0;
}

void sortpoint()
{
    vector<point>::iterator p;
    loop(i, init)
    {
        p = lower_bound(all(sorted), *i, compare);
        if(p == sorted.end()) sorted.pb(*i);
        else if(compare(*p, *i)) sorted.insert(p + 1, *i);
        else if(compare(*i, *p)) sorted.insert(p, *i);
        else if(base.diff(*p) < base.diff(*i)) *p = *i;
    }
    sorted.insert(sorted.begin(), base);
}

void convexhull()
{
    sortpoint();

    loop(p, sorted)
    {
        while(convex.size() >= 3)
        {
            point& a = *(convex.end() - 2);
            point& b = *(convex.end() - 1);
            ll d = direction(b, *p, a);
            if(d < 0) break;
            convex.pop_back();
        }
        convex.push_back(*p);
    }

    convex.pb(convex[0]);
}

int main()
{
    scanf("%d", &test);
    printf("%d\n", test);
    while(test--)
    {
        int n;
        point p;

        init.clear();
        sorted.clear();
        convex.clear();
        base = point(INT_MAX, INT_MAX);

        scanf("%d", &n);
        while(n--)
        {
            scanf("%lld %lld", &p.x, &p.y);
            if(n)
            {
                init.pb(p);
                if(p < base) base = p;
            }
        }

        convexhull();

        printf("%d\n", convex.size());
        loop(it, convex) printf("%lld %lld\n", it->x, it->y);

        if(test) printf("-1\n");
        scanf("%d", &cas); //extra -1
    }

    return 0;
}
