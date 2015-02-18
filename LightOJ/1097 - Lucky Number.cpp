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

#define MAX 100000
#define SIZ 1429450
#define MXSIZ 4194500
int tree[MXSIZ];
int ans[MAX + 10];

void build(int nod, int b, int e)
{
    if(b == e)
    {
        tree[nod] = b & 1;
        return;
    }

    int l = nod << 1;
    int r = l + 1;
    int m = (b + e) >> 1;

    build(l, b, m);
    build(r, 1 + m, e);

    tree[nod] = tree[l] + tree[r];
}

int query(int nod, int b, int e, int p)
{
    if(b == e) return b;

    int l = nod << 1;
    int r = l + 1;
    int m = (b + e) >> 1;

    if(p <= tree[l]) return query(l, b, m, p);
    else return query(r, 1 + m, e, p - tree[l]);
}

void update(int nod, int b, int e, int p)
{
    if(b == e)
    {
        tree[nod] = 0;
        return;
    }

    int l = nod << 1;
    int r = l + 1;
    int m = (b + e) >> 1;

    int res = 0;
    if(p <= tree[l]) update(l, b, m, p);
    else update(r, 1 + m, e, p - tree[l]);

    tree[nod] = tree[l] + tree[r];
}

void precalc()
{
    build(1, 1, SIZ);

    ans[1] = 1;
    for(int i = 2; i <= MAX; ++i)
    {
        int x = query(1, 1, SIZ, i);
        ans[i] = x--;
        for(int j = x + 1; j <= tree[1]; j += x)
        {
            update(1, 1, SIZ, j);
        }
    }
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    precalc();
    int n, x;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        printf("Case %d: %d\n", cas++, ans[n]);
    }

    return 0;
}
