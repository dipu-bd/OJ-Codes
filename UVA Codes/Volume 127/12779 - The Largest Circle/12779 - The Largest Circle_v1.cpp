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
typedef unsigned long long ull;
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
#define LB lower_bound
#define UB upper_bound
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

struct point
{
    int x;
    int y;
    bool zero() { return !(x || y); }
};

struct line
{
    int A;
    int B;
    int C;

    line(point a, point b)
    {
        int xd = a.x - b.x;
        int yd = a.y - b.y;
        A = yd;
        B = -xd;
        C = -a.x * yd + a.y * xd;
    }

    pii dist(point a)
    {
        int sum = A * A + B * B;
        int den = sqrt(sum);
        if(den * den != sum) return mp(0, 0);
        den *= 2;
        int num = abs(A * a.x + B * a.y + C);
        int g = gcd(num, den);
        num /= g, den /= g;
        return mp(num, den);
    }
};

int get(point& a, point& b, point& c, point& d)
{
    return scanf("%d %d %d %d %d %d %d %d",
                 &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
}

bool intersect(line& a, line& b)
{
    return (a.A * b.B - b.A * a.B) != 0;
}

bool comp(const pii& a, const pii& b)
{
    return (a.fr * b.sc <= b.fr * a.sc);
}


int main()
{
#ifdef LOCAL
    freopen("12779.inp", "r", stdin);
#endif // LOCAL

    point a, b, c, d;
    while(get(a, b, c, d) != EOF)
    {
        if(a.zero() && b.zero() && c.zero() && d.zero()) break;

        line ab(a, b);
        line ad(a, d);
        line ac(a, c);
        line bc(b, c);
        line bd(b, d);
        line cd(c, d);

        pii rad = mp(0, 0);

        if(!intersect(ab, cd))
        {
            if(!intersect(ac, bd))
            {
                pii x = bd.dist(a);
                pii y = cd.dist(a);
                rad = comp(x, y) ? x : y;
            }
            else if(!intersect(ad, bc))
            {
                pii x = bc.dist(a);
                pii y = cd.dist(a);
                rad = comp(x, y) ? x : y;
            }
        }
        else if(!intersect(ad, bc))
        {
            if(!intersect(ac, bd))
            {
                pii x = bd.dist(a);
                pii y = bc.dist(a);
                rad = comp(x, y) ? x : y;
            }
            else if(!intersect(ab, cd))
            {
                pii x = cd.dist(a);
                pii y = bc.dist(a);
                rad = comp(x, y) ? x : y;
            }
        }

        rad.fr *= rad.fr;
        rad.sc *= rad.sc;
        if(rad.sc)
        {
            ll g = (rad.fr, rad.sc);
            rad.fr /= g, rad.sc /= g;
        }

        if(rad.fr == 0 || rad.sc == 0)
        {
            printf("-1\n");
        }
        else
        {
            printf("(%d/%d)*pi\n", rad.fr, rad.sc);
        }
    }

    return 0;
}
