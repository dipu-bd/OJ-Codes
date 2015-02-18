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
typedef long long LL;
typedef unsigned long long ULL;
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
#define NL putchar('\n')
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

struct elem
{
    int x;
    int p;
    char s;
    bool operator < (const elem& r) const
    {
        if(x != r.x) return x < r.x;
        return s < r.s;
    }
};

#define SIZ 50004
vector<elem> point;
int tree[SIZ << 2];
int res[SIZ];

void update(int nod, int b, int e, int p, int v)
{
    if(b == e)
    {
        tree[nod] = v;
        return;
    }

    int m = (b + e) >> 1;
    int l = nod << 1;
    int r = l + 1;

    if(p <= m) update(l, b, m, p, v);
    else update(r, 1 + m, e, p, v);
    tree[nod] = tree[l] + tree[r];
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    elem em;
    int n, q, x, y;

    scanf("%d", &test);
    while(test--)
    {
        clr(tree);
        point.clear();

        scanf("%d %d", &n, &q);

        REPE(i, 1, n)
        {
            scanf("%d %d", &x, &y);
            if(x > y) swap(x, y);
            em.p = i;
            em.x = x;
            em.s = 0;
            point.pb(em);
            em.x = y;
            em.s = 2;
            point.pb(em);
        }
        REPE(i, 1, q)
        {
            scanf("%d", &x);
            em.p = i;
            em.x = x;
            em.s = 1;
            point.pb(em);
        }

        ssort(point);

        loop(it, point)
        {
            if(it->s == 1)
            {
                res[it->p] = tree[1];
            }
            else if(it->s == 0)
            {
                update(1, 1, n, it->p, 1);
            }
            else
            {
                update(1, 1, n, it->p, 0);
            }
        }

        printf("Case %d:\n", cas++);
        REPE(i, 1, q) printf("%d\n", res[i]);
    }

    return 0;
}
