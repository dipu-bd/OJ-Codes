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

#define SIZ 505
int n, m, v;
int x1, x2, y1, y2;
int mat[SIZ][SIZ];

void build(elem* tree, int nod, int b, int e, int r = -1)
{
    if(b == e)
    {
        tree[nod].maxx = mat[r][b];
        tree[nod].minn = mat[r][b];
        return;
    }

    int l = nod << 1;
    int r = l + 1;
    int m = (b + e) >> 1;

    build(tree, l, b, m, r);
    build(tree, r, 1 + m, e, r);

    tree[nod].maxx = max(tree[l].maxx, tree[r].maxx);
    tree[nod].minn = min(tree[l].minn, tree[r].minn);
}

pii query(elem* tree, int nod, int b, int e, int i, int j, int r = -1)
{
    if(b == e)
    {
        if(r == -1)
        {
            if(tree[nod].seg) delete tree[nod].seg;
            tree[nod].seg = new elem[SIZ << 2];
            return query(tree[nod].seg, 1, 1, m, y1, y2, b);
        }
        else
        {
            return query()
        }
        return;
    }

    int l = nod << 1;
    int r = l + 1;
    int m = (b + e) >> 1;
    pii res = mp(INT_MIN, INT_MAX);

    if(x1 <= query(tree, l, b, m, r);
    query(tree, r, 1 + m, e, r);

    tree[nod].maxx = max(tree[l].maxx, tree[r].maxx);
    tree[nod].minn = min(tree[l].minn, tree[r].minn);
}

int main()
{
#ifdef LOCAL
    freopen("11297.inp", "r", stdin);
#endif // LOCAL

    scanf("%d %d", &n, &m);
    REPE(i, 1, n)
    REPE(j, 1, m)
    scanf("%d", mat[i] + j);

    build(seg, 1, 1, n);

    int q;
    char ch;
    scanf("%d", &q);
    while(q--)
    {
        scanf(" %c", &ch);
        if(ch == 'c')
        {

        }
        else
        {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            pii r = query(seg, 1, 1, n, x1, y1);
            printf("%d %d\n", r.fr, r.sc);
        }
    }

    return 0;
}
