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
    int v;
    ll sum;
    elem() : v(-1), sum(0) { }
};

elem* tree;

void relax(int& nod, int& b, int& e, int& l, int& r, int& m)
{
    int& v = tree[nod].v;
    if(v >= 0)
    {
        tree[l].v = v;
        tree[l].sum = (ll)v * (m - b + 1);
        tree[r].v = v;
        tree[r].sum = (ll)v * (e - m);
        v = -1;
    }
}

void update(int nod, int b, int e, int i, int j, const int& v)
{
    if(i <= b && e <= j)
    {
        tree[nod].v = v;
        tree[nod].sum = v * (e - b + 1);
        return;
    }

    int l = nod << 1;
    int r = l + 1;
    int m = (b + e) >> 1;

    relax(nod, b, e, l, r, m);

    if(i <= m) update(l, b, m, i, j, v);
    if(j > m) update(r, m + 1, e, i, j, v);

    tree[nod].sum = tree[l].sum + tree[r].sum;
}

ll query(int nod, int b, int e, int i, int j)
{
    if(i <= b && e <= j) return tree[nod].sum;

    int l = nod << 1;
    int r = l + 1;
    int m = (b + e) >> 1;

    relax(nod, b, e, l, r, m);

    ll sum = 0;
    if(i <= m) sum += query(l, b, m, i, j);
    if(j > m) sum += query(r, m + 1, e, i, j);

    return sum;
}

int main()
{
#ifdef LOCAL
    freopen("1183.inp", "r", stdin);
#endif // LOCAL

    int n, q, t, x, y, v;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &q);

        if(tree) delete tree;
        tree = new elem[n << 2];

        printf("Case %d:\n", cas++);

        while(q--)
        {
            scanf("%d %d %d", &t, &x, &y);

            if(t == 1)
            {
                scanf("%d", &v);
                update(1, 1, n, x + 1, y + 1, v);
            }
            else
            {
                ll num = query(1, 1, n, x + 1, y + 1);
                if(num == 0) printf("0\n");
                else
                {
                    ll den = (y - x + 1);
                    ll g = gcd(num, den);
                    num /= g, den /= g;
                    if(den > 1) printf("%lld/%lld\n", num, den);
                    else printf("%lld\n", num);
                }
            }
        }
    }

    return 0;
}
