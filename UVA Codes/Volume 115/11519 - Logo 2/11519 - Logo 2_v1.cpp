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

const double PI = 2.0 * acos(0.0);
const double EPS = 1e-12;

struct point
{
    double x;
    double y;
    double th;
    point()  { x = y = th = 0; }

    void rotate(double d, char t)
    {
        if(t == 'r') d = -d;
        th += PI * d / 180.0;
    }

    void move(double u, char t)
    {
        if(t == 'f')
        {
            x += u * cos(th);
            y += u * sin(th);
        }
        else
        {
            x += u * cos(PI + th);
            y += u * sin(PI + th);
        }
    }

    double operator - (const point& r) const
    {
        double xd = x - r.x;
        double yd = y - r.y;
        return sqrt(xd * xd + yd * yd);
    }
};

int main()
{
#ifdef LOCAL
    freopen("11519.inp", "r", stdin);
#endif // LOCAL

    int n;
    double u;
    char com[5], sav[5];

    scanf("%d", &test);
    while(test--)
    {
        point p, q;

        scanf("%d", &n);
        while(n--)
        {
            scanf(" %s ", com);

            if(cin.peek() == '?')
            {
                q = p;
                strcpy(sav, com);
                cin.get();
            }
            else
            {
                scanf("%lf", &u);
                if(com[1] == 't') //lt or rt
                    p.rotate(u, com[0]);
                else // fd or bk
                    p.move(u, com[0]);
            }
        }

        if(fabs(p.x) < EPS && fabs(p.y) < EPS)
        {
            printf("0\n");
            continue;
        }

        if(sav[1] == 't') //rotate
        {
            double po = sqrt(p.x * p.x + p.y * p.y);
            double qo = sqrt(q.x * q.x + q.y * q.y);
            double res = 2 * asin(0.5 * po / qo);

            double d = q.y * (p.x - q.x) - q.x * (p.y - q.y);
            if(d > 0) res = -res;
            if(sav[0] == 'r') res = -res;

            int out = round(res * 180 / PI);
            out %= 360;
            if(out < 0) out += 360;
            printf("%d\n", out);
        }
        else //move
        {
            double res = sqrt(p.x * p.x + p.y * p.y);
            printf("%.0lf\n", res);
        }
    }

    return 0;
}
