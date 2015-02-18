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

struct elem
{
    int cnt;
    bool set;
    bool inv;
    bool pset;

    void clear()
    {
        cnt = 0;
        set = 0;
        inv = 0;
        pset = 0;
    }

    void setval(bool s, int range)
    {
        set = s;
        pset = 1;
        cnt = range * s;
        inv = 0;
    }

    void inverse(int range)
    {
        inv = !inv;
        cnt = range - cnt;
    }

    void print()
    {
        printf("SET: %d; PSET: %d; INV: %d; cnt: %d;\n", set, pset, inv, cnt);
    }
};

#define SIZ 1024010
int n;
char arr[SIZ];
elem tree[SIZ << 2];

void relax(int nod, int l, int r, int b, int e, int m)
{
    if(tree[nod].pset)
    {
        tree[nod].pset = 0;
        tree[l].setval(tree[nod].set, m - b + 1);
        tree[r].setval(tree[nod].set, e - m);
    }

    if(tree[nod].inv)
    {
        tree[nod].inv = 0;
        tree[l].inverse(m - b + 1);
        tree[r].inverse(e - m);
    }
}

void update(int nod, int b, int e, int i, int j, char ch)
{
    if(i <= b && e <= j)
    {
        if(ch == 'F') //set all to 1
            tree[nod].setval(1, e - b + 1);
        else if(ch == 'E') //set all to 0
            tree[nod].setval(0, e - b + 1);
        else // I : inverse all
            tree[nod].inverse(e - b + 1);
        return;
    }

    int l = nod << 1;
    int r = l + 1;
    int m = (b + e) >> 1;

    relax(nod, l, r, b, e, m);

    if(i <= m) update(l, b, m, i, j, ch);
    if(j > m) update(r, 1 + m, e, i, j, ch);

    tree[nod].cnt = tree[l].cnt + tree[r].cnt;
}

int query(int nod, int b, int e, int i, int j)
{
    if(i <= b && e <= j)
        return tree[nod].cnt;

    int l = nod << 1;
    int r = l + 1;
    int m = (b + e) >> 1;

    relax(nod, l, r, b, e, m);

    int sum = 0;
    if(i <= m) sum += query(l, b, m, i, j);
    if(j > m) sum += query(r, 1 + m, e, i, j);

    return sum;
}

void build(int nod, int b, int e)
{
    if(b == e)
    {
        tree[nod].clear();
        tree[nod].cnt = (arr[b] - '0');
        return;
    }

    int l = nod << 1;
    int r = l + 1;
    int m = (b + e) >> 1;

    build(l, b, m);
    build(r, 1 + m, e);

    tree[nod].clear();
    tree[nod].cnt = tree[l].cnt + tree[r].cnt;
}

int main()
{
#ifdef LOCAL
    freopen("11402.inp", "r", stdin);
#endif // LOCAL

    int m, t, len;
    int q, a, b, qc;
    char ch, inp[100];

    scanf("%d", &test);
    while(test--)
    {
        n = 0;
        scanf("%d", &m);

        while(m--)
        {
            scanf("%d", &t);
            scanf(" %s", inp);
            len = strlen(inp);

            while(t--)
            {
                REP(i, 0, len)
                arr[++n] = inp[i];
            }
        }

        build(1, 1, n);
        printf("Case %d:\n", cas++);

        qc = 1;
        scanf("%d", &q);
        while(q--)
        {
            scanf(" %c %d %d", &ch, &a, &b);
            ++a, ++b;

            if(ch == 'S') //query
            {
                t = query(1, 1, n, a, b);
                printf("Q%d: %d\n", qc++, t);
            }
            else
            {
                update(1, 1, n, a, b, ch);
            }
        }
    }

    return 0;
}
