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

#define SIZ 250003
int nx, ny, n;
int mat[SIZ];
pii tree[SIZ << 2];

void build(int nod, int b, int e)
{
    if(b == e)
    {
        tree[nod].fr = mat[b];
        tree[nod].sc = mat[b];
        return;
    }

    int m = (b + e) >> 1;
    int l = nod << 1;
    int r = l + 1;

    build(l, b, m);
    build(r, 1 + m, e);

    tree[nod].fr = max(tree[l].fr, tree[r].fr);
    tree[nod].sc = min(tree[l].sc, tree[r].sc);
}

void update(int nod, int b, int e, int x, int v)
{
    if(b == e)
    {
        tree[nod].fr = v;
        tree[nod].sc = v;
        return;
    }

    int m = (b + e) >> 1;
    int l = nod << 1;
    int r = l + 1;

    if(x <= m) update(l, b, m, x, v);
    else update(r, 1 + m, e, x, v);

    tree[nod].fr = max(tree[l].fr, tree[r].fr);
    tree[nod].sc = min(tree[l].sc, tree[r].sc);
}

void apply(pii& a, const pii& b)
{
    if(a.first < b.first) a.first = b.first;
    if(a.second > b.second) a.second = b.second;
}

pii query(int nod, int b, int e, int i, int j)
{
    if(i <= b && e <= j) return tree[nod];

    int m = (b + e) >> 1;
    int l = nod << 1;
    int r = l + 1;

    pii res = mp(INT_MIN, INT_MAX);
    if(i <= m) apply(res, query(l, b, m, i, j));
    if(j > m) apply(res, query(r, 1 + m, e, i, j));

    return res;
}

inline int idx(int x, int y)
{
    return (x - 1) * ny + (y - 1) + 1;
}

int main()
{
#ifdef LOCAL
    freopen("11297.inp", "r", stdin);
#endif // LOCAL

    while(scanf("%d %d", &nx, &ny) != EOF)
    {
        REPE(i, 1, nx)
        REPE(j, 1, ny)
        scanf("%d", mat + idx(i, j));

        n = nx * ny;
        build(1, 1, n);

        int q;
        scanf("%d", &q);
        while(q--)
        {
            char t;
            scanf(" %c", &t);
            if(t == 'c')
            {
                int x, y, v;
                scanf("%d %d %d", &x, &y, &v);
                update(1, 1, n, idx(x, y), v);
            }
            else
            {
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

                pii res = mp(INT_MIN, INT_MAX);
                REPE(i, x1, x2)
                {
                    apply(res, query(1, 1, n, idx(i, y1), idx(i, y2)));
                }

                printf("%d %d\n", res.first, res.second);
            }
        }
    }

    return 0;
}
