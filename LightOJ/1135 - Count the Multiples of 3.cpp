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

struct elem
{
    int prop; //propagate
    int zero;
    int one;
    int two;
    elem() : zero(0), one(0), two(0), prop(0) { }

    void apply(int p) //increase all by 1 for p times
    {
        int n[3];
        n[(0 + p) % 3] = zero;
        n[(1 + p) % 3] = one;
        n[(2 + p) % 3] = two;

        zero = n[0];
        one = n[1];
        two = n[2];

        prop += p;
    }

    elem operator + (const elem& b)
    {
        elem r;
        r.zero = zero + b.zero;
        r.one = one + b.one;
        r.two = two + b.two;
        return r;
    }
};

#define SIZ 100000
elem tree[SIZ << 2];

inline void relax(int nod, int l, int r)
{
    if(!tree[nod].prop) return;
    tree[l].apply(tree[nod].prop);
    tree[r].apply(tree[nod].prop);
    tree[nod].prop = 0;
}

void update(int nod, int b, int e, int i, int j)
{
    if(i <= b && e <= j)
    {
        tree[nod].apply(1);
        return;
    }

    int l = nod << 1;
    int r = l + 1;
    int m = (b + e) >> 1;

    relax(nod, l, r);

    if(i <= m) update(l, b, m, i, j);
    if(j > m) update(r, 1 + m, e, i, j);

    tree[nod] = tree[l] + tree[r];
}

int query(int nod, int b, int e, int i, int j)
{
    if(i <= b && e <= j) return tree[nod].zero;

    int l = nod << 1;
    int r = l + 1;
    int m = (b + e) >> 1;

    relax(nod, l, r);

    int res = 0;
    if(i <= m) res += query(l, b, m, i, j);
    if(j > m) res += query(r, m + 1, e, i, j);

    return res;
}

void build(int nod, int b, int e)
{
    if(b == e)
    {
        tree[nod] = elem();
        tree[nod].zero = 1;
        return;
    }

    int l = nod << 1;
    int r = l + 1;
    int m = (b + e) >> 1;

    build(l, b, m);
    build(r, 1 + m, e);

    tree[nod] = elem();
    tree[nod].zero = e - b + 1;
}

int main()
{
#ifdef LOCAL
    freopen("1135.inp", "r", stdin);
#endif // LOCAL

    int n, q, t, x, y;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &q);

        build(1, 1, n);

        printf("Case %d:\n", cas++);
        while(q--)
        {
            scanf("%d %d %d", &t, &x, &y);

            if(t == 0)
            {
                update(1, 1, n, x + 1, y + 1);
            }
            else
            {
                int res = query(1, 1, n, x + 1, y + 1);
                printf("%d\n", res);
            }

            //printf("[%d %d %d]\n", tree[1].zero, tree[1].one, tree[1].two);
        }
    }

    return 0;
}
