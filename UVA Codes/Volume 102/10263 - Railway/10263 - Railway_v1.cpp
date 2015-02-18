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
    double x;
    double y;
    point(double a = 0, double b = 0) : x(a), y(b) { }
};

double dist(const point& a, const point& b)
{
    double xd = a.x - b.x;
    double yd = a.y - b.y;
    return sqrt(xd * xd + yd * yd);
}

point middle(const point& a, const point& b, const point& m)
{
    double xd = a.x - b.x;
    double yd = a.y - b.y;
    double c = xd * a.y - yd * a.x;
    double k = yd * m.y + xd * m.x;
    double xt = xd * k - yd * c;
    double yt = yd * k + xd * c;
    double bt = xd * xd + yd * yd;
    return point(xt / bt, yt / bt);
}

bool onsegment(const point& a, const point& b, const point& m)
{
    double xi = a.x;
    double xj = b.x;
    if(xi > xj) swap(xi, xj);
    double yi = a.y;
    double yj = b.y;
    if(yi > yj) swap(yi, yj);
    return (xi <= m.x && m.x <= xj) &&
           (yi <= m.y && m.y <= yj);
}

int main()
{
#ifdef LOCAL
    freopen("10263.inp", "r", stdin);
#endif // LOCAL

    int n;
    point m;
    point a, b;
    point mr, tr;
    double md, td, ttd;
    while(scanf("%lf %lf", &m.x, &m.y) != EOF)
    {
        scanf("%d", &n);
        scanf("%lf %lf", &a.x, &a.y);

        mr = a, md = dist(a, m);
        while(n--)
        {
            scanf("%lf %lf", &b.x, &b.y);
            tr = middle(a, b, m);
            if(onsegment(a, b, tr))
            {
                td = dist(tr, m);
            }
            else
            {
                td = dist(a, m);
                ttd = dist(b, m);
                if(td <= ttd) tr = a;
                else tr = b, td = ttd;
            }

            if(td < md) md = td, mr = tr;
            a = b;
        }

        printf("%.4lf\n%.4lf\n", mr.x, mr.y);
    }

    return 0;
}
