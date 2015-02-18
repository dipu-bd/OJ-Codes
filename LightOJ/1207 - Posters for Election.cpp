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


#define SIZ 200010
int total;
bool wall[SIZ];
int tree[SIZ << 2];

void relax(int nod, int l, int r)
{
    if(!tree[nod]) return;
    tree[l] = tree[nod];
    tree[r] = tree[nod];
    tree[nod] = 0;
}

void update(int nod, int b, int e, int i, int j, int q)
{
    if(i <= b && e <= j)
    {
        tree[nod] = q;
        return;
    }

    int l = nod << 1;
    int r = l + 1;
    int m = (b + e) >> 1;

    relax(nod, l, r);
    if(i <= m) update(l, b, m, i, j, q);
    if(j > m) update(r, 1 + m, e, i, j, q);
}

void countall(int nod, int b, int e)
{
    if(b == e)
    {
        int q = tree[nod];
        if(q && !wall[q])
        {
            wall[q] = 1;
            ++total;
        }
        return;
    }

    int l = nod << 1;
    int r = l + 1;
    int m = (b + e) >> 1;

    relax(nod, l, r);
    countall(l, b, m);
    countall(r, 1 + m, e);
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int n, m, x, y;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);

        clr(tree);
        m = n << 1;
        REPE(i, 1, n)
        {
            scanf("%d %d", &x, &y);
            update(1, 1, m, x, y, i);
        }

        total = 0;
        clr(wall);
        countall(1, 1, m);

        printf("Case %d: %d\n", cas++, total);
    }

    return 0;
}
