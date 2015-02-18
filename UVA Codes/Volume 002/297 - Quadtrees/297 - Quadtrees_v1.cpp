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

int len;
char pre[10000];
char tree[10000];

int build(int nod, int p)
{
    if(p >= len) return p;

    if(pre[p] != 'p')
    {
        if(pre[p] == 'f')
            tree[nod] = 'f';
        else if(tree[nod] != 'f' && tree[nod] != 'p')
            tree[nod] = pre[p];

        return p;
    }

    int c3 = nod << 2;
    int c2 = c3 - 1;
    int c1 = c2 - 1;
    int c4 = c3 + 1;

    p = build(c1, p + 1);
    p = build(c2, p + 1);
    p = build(c3, p + 1);
    p = build(c4, p + 1);

    if(tree[nod] != 'f') tree[nod] = 'p';
    return p;
}

int query(int nod, int lev = 1)
{
    if(tree[nod] == 0) return 0;
    if(tree[nod] == 'e') return 0;
    if(tree[nod] == 'f') return (1024 / lev);

    int sum = 0;

    int c3 = nod << 2;
    int c2 = c3 - 1;
    int c1 = c2 - 1;
    int c4 = c3 + 1;

    sum += query(c1, lev << 2);
    sum += query(c2, lev << 2);
    sum += query(c3, lev << 2);
    sum += query(c4, lev << 2);

    return sum;
}

int main()
{
#ifdef LOCAL
    freopen("297.inp", "r", stdin);
#endif // LOCAL

    scanf("%d", &test);
    while(test--)
    {
        clr(tree);

        scanf(" %s", pre);
        len = strlen(pre);
        build(1, 0);

        scanf(" %s", pre);
        len = strlen(pre);
        build(1, 0);

        int res = query(1);
        printf("There are %d black pixels.\n", res);
    }

    return 0;
}
