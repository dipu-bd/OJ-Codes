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
int prev[SIZ];
int res[SIZ];
int tree[SIZ << 2];
vector<pii> saved[SIZ];

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
    if(p > m) update(r, 1 + m, e, p, v);

    tree[nod] = tree[l] + tree[r];
}

int query(int nod, int b, int e, int i, int j)
{
    if(i <= b && e <= j)
        return tree[nod];

    int m = (b + e) >> 1;
    int l = nod << 1;
    int r = l + 1;

    int cnt = 0;
    if(i <= m) cnt += query(l, b, m, i, j);
    if(j > m) cnt += query(r, 1 + m, e, i, j);

    return cnt;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int n, q, x, y;

    scanf("%d", &test);
    while(test--)
    {
        clr(tree);
        clr(prev);

        scanf("%d %d", &n, &q);
        REPE(i, 1, n)
        {
            scanf("%d", arr + i);
            saved[i].clear();
        }
        REPE(i, 1, q)
        {
            scanf("%d %d", &x, &y);
            saved[y].pb(mp(x, i));
        }

        REPE(y, 1, n)
        {
            int v = arr[y];
            if(prev[v]) update(1, 1, n, prev[v], 0);
            update(1, 1, n, y, 1);
            prev[v] = y;

            loop(it, saved[y])
            {
                res[it->sc] = query(1, 1, n, it->fr, y);
            }
        }

        printf("Case %d:\n", cas++);
        REPE(i, 1, q) printf("%d\n", res[i]);
    }

    return 0;
}
