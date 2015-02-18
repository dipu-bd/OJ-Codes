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
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
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
/*------------------------------------------------------------------------------------------------*/

int test, cas = 1;
#define putcas1 printf("Case %d: ", cas++)
#define putcas2 printf("Case %d:\n", cas++)


inline void apply(pii& a, const pii& b)
{
    if(b.fr < a.fr) a.fr = b.fr;
    if(b.sc > a.sc) a.sc = b.sc;
}

inline int diff(const pii& a)
{
    return (a.sc - a.fr);
}

#define MAX 100005
int n, d;
int dat[MAX];
pii tree[MAX << 2];

void build(int nod, int b, int e)
{
    if(b == e)
    {
        tree[nod].fr = dat[b];
        tree[nod].sc = dat[b];
        return;
    }

    int m = (b + e) >> 1;
    int l = nod << 1;
    int r = l + 1;
    build(l, b, m);
    build(r, m + 1, e);
    tree[nod].fr = min(tree[l].fr, tree[r].fr);
    tree[nod].sc = max(tree[l].sc, tree[r].sc);
}

pii query(int nod, int b, int e, int i, int j)
{
    if(i <= b && e <= j) return tree[nod];

    int m = (b + e) >> 1;
    int l = nod << 1;
    int r = l + 1;

    pii res = mp(INT_MAX, INT_MIN);
    if(i <= m) apply(res, query(l, b, m, i, j));
    if(j > m) apply(res, query(r, m + 1, e, i, j));

    return res;
}

int main()
{
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &d);
        REPE(i, 1, n) scanf("%d", dat + i);

        build(1, 1, n);

        int res = 0;
        REPE(i, d, n)
        {
            res = max(res, diff(query(1, 1, n, i - d + 1, i)));
        }

        putcas1;
        printf("%d\n", res);
    }

    return 0;
}

