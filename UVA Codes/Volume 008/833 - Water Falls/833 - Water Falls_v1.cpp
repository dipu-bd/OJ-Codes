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
    int x;
    int y;
};

struct line
{
    point a;
    point b;

    line(const point& p, const point& q)
    {
        a = p, b = q;
        if(q.x < p.x) swap(a, b);
    }

    bool operator < (const line& r) const
    {
        return b.x < r.b.x;
    }
};

vector<line> ve;

double gety(const line& p, int x)
{
    double pdx = p.a.x - p.b.x;
    double pdy = p.a.y - p.b.y;
    return pdy * (x - p.a.x) / pdx + p.a.y;
}

bool isabove(const line& p, const line& q, int x)
{
    double py = gety(p, x);
    double qy = gety(q, x);
    return py > qy;
}

int ground(point a)
{
    set<int> disable;
    while(true)
    {
        int i = 0;
        while(i < ve.size() && ve[i].b.x <= a.x) ++i;
        if(i >= ve.size()) return a.x;

        int h = -1;
        for( ; i < ve.size(); ++i)
        {
            if(ve[i].a.x < a.x)
            {
                if(disable.count(i)) continue;
                if(gety(ve[i], a.x) > a.y) continue;
                if(h == -1) h = i;
                else if(isabove(ve[i], ve[h], a.x)) h = i;
            }
        }

        if(h == -1) return a.x;

        disable.insert(h);
        a = (ve[h].a.y < ve[h].b.y) ? ve[h].a : ve[h].b;
    }
}

int main()
{
#ifdef LOCAL
    freopen("833.inp", "r", stdin);
#endif // LOCAL

    int n, m;

    scanf("%d", &test);
    while(test--)
    {
        ve.clear();
        point a, b;

        scanf("%d", &n);
        while(n--)
        {
            scanf("%d %d", &a.x, &a.y);
            scanf("%d %d", &b.x, &b.y);
            if(a.x != b.x) ve.pb(line(a, b));
        }

        ssort(ve);

        scanf("%d", &m);
        while(m--)
        {
            scanf("%d %d", &a.x, &a.y);
            int x = ground(a);
            printf("%d\n", x);
        }

        if(test) putchar('\n');
    }

    return 0;
}

