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

#define SIZ 100005
int arr[SIZ];
int tree[SIZ << 2];

inline int sign(const int& v) { return (v < 0) ? -1 : (v == 0 ? 0 : 1); }

void build(int nod, int b, int e)
{
    if(b == e)
    {
        tree[nod] = sign(arr[b]);
        return;
    }

    int l = nod << 1;
    int r = l + 1;
    int m = (b  + e) >> 1;

    build(l, b, m);
    build(r, 1 + m, e);

    tree[nod] = tree[l] * tree[r];
}

void update(int nod, int b, int e, int p, int v)
{
    if(b == e)
    {
        tree[nod] = sign(v);
        return;
    }

    int l = nod << 1;
    int r = l + 1;
    int m = (b  + e) >> 1;

    if(p <= m) update(l, b, m, p, v);
    if(p > m) update(r, 1 + m, e,  p, v);

    tree[nod] = tree[l] * tree[r];
}

int query(int nod, int b, int e, int i, int j)
{
    if(i <= b && e <= j)
        return tree[nod];

    int l = nod << 1;
    int r = l + 1;
    int m = (b  + e) >> 1;

    int res = 1;
    if(i <= m) res *= query(l, b, m, i, j);
    if(j > m) res *= query(r, 1 + m, e,  i, j);

    return res;
}

int main()
{
#ifdef LOCAL
    freopen("12532.inp", "r", stdin);
#endif // LOCAL

    int n, k;
    char com;
    int x, y;

    while(scanf("%d %d", &n, &k) != EOF)
    {
        REPE(i, 1, n) scanf("%d", arr + i);

        build(1, 1, n);

        while(k--)
        {
            scanf(" %c %d %d", &com, &x, &y);
            if(com == 'C')
            {
                update(1, 1, n, x, y);
            }
            else
            {
                int q = query(1, 1, n, x, y);
                if(q == 0) putchar('0');
                else (q > 0 ? putchar('+') : putchar('-'));
            }
        }

        putchar('\n');
    }

    return 0;
}
