//c headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
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
using namespace std;

const double EPS = 1E-12;
const double PI = 2.0 * acos(0.0);
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vii;
typedef vector<pii> vpii;

#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a,0,sizeof(a))
#define mem(a,b) memset(a,b,sizeof(a))
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define ins insert
#define mp make_pair
#define IT iterator
#define ssort(v) stable_sort(v.begin(), v.end())
#define all(v) (v.begin(), v.end())
#define loop(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i = (x).rbegin(); i != (x).rend(); ++i)
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define LB lower_bound
#define UB upper_bound
template<typename T> inline T sqr(T n) { return n * n; }

int test, cas = 1;

struct point
{
    char ox[50], oy[50];
    double x, y;
    point(double a = 0, double b = 0) : x(a), y(b) { }

    bool operator < (const point& r) const
    {
        if (fabs(y - r.y) < EPS)
            return (x < r.x + EPS);
        return (y < r.y + EPS);
    }
};

int bindx;
point base;
vii sorted, convex;
vector<point> init;

void clearall()
{
    init.clear();
    sorted.clear();
    convex.clear();
    base = point(LONG_LONG_MAX, LONG_LONG_MAX);
}

double direction(point b, point f, point t)
{
    return (t.x - b.x) * (f.y - b.y) - (t.y - b.y) * (f.x - b.x);
}

double diff(const point& a, const point& b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool compare(const int& a, const int& b)
{
    return direction(base, init[a], init[b]) < -EPS;
}

void sortpoint()
{
    vii::iterator p;
    REP(i, 0, init.size())
    {
        p = LB(sorted.begin(), sorted.end(), i, compare);
        if(p == sorted.end()) sorted.pb(i);
        else if(compare(*p, i)) sorted.insert(p + 1, i);
        else if(compare(i, *p)) sorted.insert(p, i);
        else if(diff(base, init[*p]) < diff(base, init[i]) + EPS) *p = i;
    }
    sorted.insert(sorted.begin(), bindx);
}

void convexhull()
{
    loop(i, sorted)
    {
        point& p = init[*i];
        while(convex.size() >= 3)
        {
            point& a = init[*(convex.end() - 2)];
            point& b = init[*(convex.end() - 1)];
            if(direction(b, p, a) < -EPS) break;
            convex.pop_back();
        }
        convex.push_back(*i);
    }
}

char line[1000000];

int main()
{
#ifdef DIPU
    freopen("H.txt", "r", stdin);
#endif // DIPU

    point p;
    while(gets(line))
    {
        clearall();

        while(sscanf(line, " ( %[-.0-9] , %[-.0-9] )%[^\n]", p.ox, p.oy, line) == 3)
        {
            sscanf(p.ox, "%lf", &p.x);
            sscanf(p.oy, "%lf", &p.y);
            init.pb(p);
            if(p < base)
            {
                base = p;
                bindx = init.size() - 1;
            }
        }

        sscanf(p.ox, "%lf", &p.x);
        sscanf(p.oy, "%lf", &p.y);
        init.pb(p);
        if(p < base)
        {
            base = p;
            bindx = init.size() - 1;
        }

        sortpoint();
        convexhull();

        loop(i, convex)
        {
            printf("(%s,%s) ", init[*i].ox, init[*i].oy);
        }
        printf("(%s,%s)\n", init[convex[0]].ox, init[convex[0]].oy);
    }

    return 0;
}

