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

struct point
{
    int x;
    int y;
};

#define SIZ 710
point pc[SIZ];
point base;
vector<pii> took;

int dir(point& b, point& f, point& t)
{
    return (t.x - b.x) * (f.y - b.y) -
           (f.x - b.x) * (t.y - b.y);
}

bool comp(const pii& a, const pii& b)
{
    return dir(base, pc[a.fr], pc[b.fr]) < 0;
}

int main()
{
#ifdef LOCAL
    //freopen("1292.inp", "r", stdin);
#endif // LOCAL

    int n;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);

        REP(i, 0, n)
        scanf("%d %d", &pc[i].x, &pc[i].y);

        int mc = 0;
        REP(i, 0, n)
        {
            took.clear();
            base = pc[i];
            vector<pii>::IT p;
            REP(j, 0, n)
            {
                if(i == j) continue;

                pii np = mp(j, 1);
                p = lower_bound(all(took), np, comp);

                if(p == took.end())
                {
                    took.push_back(np);
                }
                else
                {
                    int d = dir(base, pc[p->fr], pc[j]);
                    if(d == 0) { ++p->sc; continue; }
                    if(d < 0) ++p;
                    took.insert(p, np);
                }
            }

            loop(p, took) if(p->sc > mc) mc = p->sc;
        }

        printf("Case %d: %d\n", cas++, mc + 1);
    }

    return 0;
}
