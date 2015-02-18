//c headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
//cpp headers
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <deque>
using namespace std;

const double EPS = 1E-10;
const double E = exp(1.0);
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

int test, cas = 1;

typedef pair<double, double> P;

struct line
{
    double x1, x2, y1, y2;
};

P MV(P a, P b)
{
    return mp(b.fr - a.fr, b.sc - a.sc);
}

double CV(P a, P b)
{
    return a.fr * b.sc - a.sc * b.fr;
}

bool onsegment(line a, double x, double y)
{
    return (min(a.x1, a.x2) <= x + EPS && x <= max(a.x1, a.x2) + EPS) &&
           (min(a.y1, a.y2) <= y + EPS && y <= max(a.y1, a.y2) + EPS);
}

bool intersect(line a, line b)
{
    double d1, d2, d3, d4;
    d1 = CV(MV(mp(b.x1, b.y1), mp(b.x2, b.y2)), MV(mp(b.x1, b.y1), mp(a.x1, a.y1)));
    d2 = CV(MV(mp(b.x1, b.y1), mp(b.x2, b.y2)), MV(mp(b.x1, b.y1), mp(a.x2, a.y2)));
    d3 = CV(MV(mp(a.x1, a.y1), mp(a.x2, a.y2)), MV(mp(a.x1, a.y1), mp(b.x1, b.y1)));
    d4 = CV(MV(mp(a.x1, a.y1), mp(a.x2, a.y2)), MV(mp(a.x1, a.y1), mp(b.x2, b.y2)));
    if(d1 * d2 < -EPS && d3 * d4 < -EPS) return true;
    if(fabs(d1) < EPS && onsegment(b, a.x1, a.y1)) return true;
    if(fabs(d2) < EPS && onsegment(b, a.x2, a.y2)) return true;
    if(fabs(d3) < EPS && onsegment(a, b.x1, b.y1)) return true;
    if(fabs(d4) < EPS && onsegment(a, b.x2, b.y2)) return true;
    return false;
}

#define SIZ 100010
line stick[SIZ];
vii taken;

int main()
{
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        REPE(i, 1, n)
        {
            scanf("%lf %lf %lf %lf", &stick[i].x1, &stick[i].y1, &stick[i].x2, &stick[i].y2);
        }

        taken.clear();
        taken.pb(n);
        RREPE(i, n - 1, 1)
        {
            bool can = true;
            REPE(j, i + 1, n)
            if(intersect(stick[j], stick[i]))
            {
                can = false;
                break;
            }
            if(can) taken.pb(i);
        }

        printf("Top sticks:");
        bool spc = false;
        rloop(it, taken)
        {
            if(spc) putchar(',');
            else spc = true;
            printf(" %d", *it);
        }
        puts(".");
    }

    return 0;
}


